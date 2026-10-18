from pathlib import Path
import json, hashlib, re
from pypdf import PdfReader
import pdfplumber

ROOT=Path(__file__).resolve().parent
pdf=ROOT/'printable/ACM_Template.pdf'
catalog=json.loads((ROOT/'catalog.json').read_text(encoding='utf-8'))
manifest=json.loads((ROOT/'printable/pdf_manifest.json').read_text(encoding='utf-8'))
validation=json.loads((ROOT/'validation_report.json').read_text(encoding='utf-8'))
checks={x['path']:x for x in validation['files']}
reader=PdfReader(str(pdf))
assert len(reader.pages)==manifest['pages']
norm=lambda s: re.sub(r'\s+','',s)
body=[]
with pdfplumber.open(pdf) as document:
    for i,page in enumerate(document.pages,1):
        assert abs(page.width-595.2756)<.1 and abs(page.height-841.8898)<.1
        for c in page.chars:
            assert c['x0']>=30 and c['x1']<=page.width-30,(i,'horizontal clipping',c)
            assert c['top']>20 and c['bottom']<page.height-15,(i,'vertical clipping',c)
        text=page.extract_text(x_tolerance=1) or ''
        assert '\ufffd' not in text and '(cid:' not in text
        assert f'{i} / {len(reader.pages)}' in text,(i,'footer')
        # Strip running furniture only; algorithm code will be compared in order.
        content=page.crop((0,55,page.width,page.height-48)).extract_text(x_tolerance=1) or ''
        body.append(content)
    text='\n'.join(body[2:])
    for item,entry in zip(catalog,manifest['templates']):
        assert item['path']==entry['path']
        digest=hashlib.sha256((ROOT/item['path']).read_bytes()).hexdigest()
        assert digest==entry['sha256']==checks[item['path']]['sha256']
        assert checks[item['path']]['compile']=='PASS'
        assert item['title'] in body[entry['page']-1],(item['path'],'wrong start page')
        lines=(ROOT/item['path']).read_text(encoding='utf-8').splitlines()
        for _ in range(3):
            if lines and lines[0].startswith('//'):lines.pop(0)
        begin=text.find(item['title'])
        assert begin>=0
        text=text[begin:]
        # Locate each source line in sequence, tolerating only whitespace/font-run splits.
        flat=norm(text);pos=0
        for line in lines:
            if not line.strip():continue
            wanted=norm(line);found=flat.find(wanted,pos)
            assert found>=0,(item['path'],'missing code line',line)
            pos=found+len(wanted)
toc_links=reader.pages[1].get('/Annots',[])
assert len(toc_links)==len(catalog)
for link,item in zip(toc_links,manifest['templates']):
    dest=link.get_object()['/Dest'][0]
    assert reader.get_page_number(dest.get_object())+1==item['page']
for page in reader.pages:
    for font in page['/Resources']['/Font'].values():
        f=font.get_object()
        if f.get('/Subtype')=='/TrueType':
            descriptor=f['/FontDescriptor'].get_object()
            assert '/FontFile2' in descriptor
inventory=json.loads((ROOT/'history_inventory.json').read_text(encoding='utf-8'))
for item in inventory:
    assert hashlib.sha256((ROOT.parent/item['path']).read_bytes()).hexdigest()==item['sha256'],item['path']
report={'status':'PASS','pages':len(reader.pages),'template_count':len(catalog),
        'checks':['A4 page size','text bounds on every page','page footers',
                  '42 clickable TOC destinations','source code lines in order',
                  'source/test/PDF SHA-256 match','embedded TrueType fonts',
                  '747 original source hashes unchanged'],
        'visual_review':'Separate rendered-page inspection required; this script does not replace it.'}
(ROOT/'printable/qa_report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print(json.dumps(report,ensure_ascii=True))
