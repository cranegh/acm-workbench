"""Rebuild the A4 handbook from catalog.json and the current .cpp files."""
from pathlib import Path
import json, re, math, hashlib, os, sys
from reportlab.pdfgen import canvas
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.pagesizes import A4
from reportlab.lib.units import mm

ROOT=Path(__file__).resolve().parent
OUT=ROOT/'printable';OUT.mkdir(exist_ok=True)
# Fonts are machine-specific. Point TEMPLATE_FONT_DIR at a directory that has
# consola/consolab/simsun, or override each file with the variables below.
FONT=Path(os.environ.get('TEMPLATE_FONT_DIR','C:/Windows/Fonts'))
CODE_FONT=Path(os.environ.get('TEMPLATE_CODE_FONT',FONT/'consola.ttf'))
CODE_BOLD_FONT=Path(os.environ.get('TEMPLATE_CODE_BOLD_FONT',FONT/'consolab.ttf'))
CJK_FONT=Path(os.environ.get('TEMPLATE_CJK_FONT',FONT/'simsun.ttc'))
missing=[p for p in (CODE_FONT,CODE_BOLD_FONT,CJK_FONT) if not p.exists()]
if missing:
    sys.exit('missing fonts: '+', '.join(map(str,missing))+
             '\nset TEMPLATE_FONT_DIR, or TEMPLATE_CODE_FONT / TEMPLATE_CODE_BOLD_FONT / TEMPLATE_CJK_FONT')
pdfmetrics.registerFont(TTFont('Code',str(CODE_FONT)))
pdfmetrics.registerFont(TTFont('Chinese',str(CJK_FONT),subfontIndex=0))
pdfmetrics.registerFont(TTFont('CodeBold',str(CODE_BOLD_FONT)))
W,H=A4;M=13*mm;WIDTH=W-2*M;TOP=H-24*mm;BOTTOM=17*mm
chapters={'00_base':'1  Base / 基础','01_data_structure':'2  Data Structure / 数据结构',
          '02_graph':'3  Graph / 图论','03_string':'4  String / 字符串',
          '04_math':'5  Math / 数学','05_dp':'6  DP / 动态规划','06_geometry':'7  Geometry / 几何'}
items=json.loads((ROOT/'catalog.json').read_text(encoding='utf-8'))
actual={p.relative_to(ROOT).as_posix() for p in ROOT.glob('*/*.cpp')}
assert actual=={x['path'] for x in items},'Update catalog.json for added/removed templates'

def runs(text,bold=False):
    return [(s,'Chinese' if ord(s[0])>127 else ('CodeBold' if bold else 'Code'))
            for s in re.findall(r'[^\x00-\x7f]+|[\x00-\x7f]+',text)]
def width(text,size,bold=False):return sum(pdfmetrics.stringWidth(s,f,size) for s,f in runs(text,bold))
def draw(c,text,x,y,size=8.5,bold=False):
    for s,f in runs(text,bold):
        c.setFont(f,size);c.drawString(x,y,s);x+=pdfmetrics.stringWidth(s,f,size)
def wrap(text,size):
    lines=['']
    for ch in text:
        if width(lines[-1]+ch,size)>WIDTH:lines.append('')
        lines[-1]+=ch
    return lines

pages=[];page={'blocks':[],'chapters':[]};y=TOP
def newpage():
    global page,y
    if page['blocks']:pages.append(page)
    page={'blocks':[],'chapters':[]};y=TOP

counts={}
for item in items:
    chapter=item['path'].split('/')[0]
    counts[chapter]=counts.get(chapter,0)+1
    item['number']=f'{list(chapters).index(chapter)+1}.{counts[chapter]}'
    raw=(ROOT/item['path']).read_text(encoding='utf-8').splitlines()
    # Metadata above already prints the leading comments.
    for _ in range(3):
        if raw and raw[0].startswith('//'):raw.pop(0)
    raw=[line for line in raw if line.strip()]
    size=min(8.5,WIDTH/max(width(line,1) for line in raw))
    assert size>=7.6,(item['path'],size)
    leading=size*1.22
    meta=wrap(item['use']+' | '+item['cost']+' | '+item['origin'],8.2)
    if item['note']:meta+=wrap(item['note'],8.2)
    header=21+len(meta)*11+5
    height=header+leading*len(raw)+15
    if height<=TOP-BOTTOM and y-height<BOTTOM:newpage()
    if height>TOP-BOTTOM and y<TOP-200:newpage()
    item['page']=len(pages)+3 # cover, contents, then body
    first=True
    while raw:
        title=item['number']+' '+item['title']+(' (续)' if not first else '')
        linesmeta=meta if first else [item['path']]
        head=21+len(linesmeta)*11+5
        available=int((y-BOTTOM-head)/leading)
        if available<5:newpage();continue
        take=min(available,len(raw))
        # Avoid a tiny continuation; move a few more lines to the next page.
        if 0<len(raw)-take<8:take=max(5,len(raw)-8)
        if take<len(raw):
            boundaries=[i+1 for i in range(max(5,take-15),take) if raw[i]=='}']
            if boundaries:take=boundaries[-1]
        block={'title':title,'meta':linesmeta,'code':raw[:take],
               'y':y,'size':size,'leading':leading,'chapter':chapter,
               'key':item['path'] if first else None}
        page['blocks'].append(block)
        if chapter not in page['chapters']:page['chapters'].append(chapter)
        y-=head+take*leading+15
        raw=raw[take:];first=False
        if raw:newpage()
newpage()

target=OUT/'ACM_Template.pdf'
c=canvas.Canvas(str(target),pagesize=A4,pageCompression=1)
c.setTitle('Personal ACM / ICPC Template');c.setAuthor('Personal competition library')
total=len(pages)+2
def furniture(number,title):
    draw(c,title,M,H-13*mm,9)
    c.setLineWidth(.4);c.line(M,H-16*mm,W-M,H-16*mm)
    c.line(M,13*mm,W-M,13*mm)
    draw(c,'Personal ACM / ICPC Template | C++17',M,9*mm,8)
    label=f'{number} / {total}';draw(c,label,W-M-width(label,8),9*mm,8)

furniture(1,'使用约定 / 2026-09-06')
draw(c,'Personal ACM / ICPC Template',M,TOP-35,20,True)
draw(c,'个人竞赛模板 · 从历史代码提取，面向铜牌巩固与银牌备赛',M,TOP-67,11)
draw(c,f'{len(items)} 个模板 / {len(chapters)} 个章节 / C++17 / int + long long',M,TOP-94,11)
intro=[
    '查找：下一页目录列出每个模板的起始页；PDF 书签可直接跳转。',
    '复制：KMP、Manacher 保留原完整程序；其他模板按各文件说明调用。',
    '组合：N、g、init、build、query 等会重名，只复制需要的部分或手动改名。',
    '下标：数组/图通常 1-index；KMP 输出 1-index，离散化/LIS 为 0-index。',
    '容量：N 包含余量，最大合法数组下标是 N-1；先按题目改 N/LOG。',
    '多测：调用 init/build；图的 g[1..旧n]、反图和边表需要自己清空。',
    '数值：总和与乘积需要在 ll 范围内；INF 不是真正无限大。',
    '写法：已有算法保留原实现；乘法用 ll，使用前核对模板注明的范围。',
    '注释：新增算法附调用例子、变量含义和关键步骤；例子写在代码旁。',
    '入门优先：树状数组、线段树、KMP、Manacher、最短路、基础数论。',
    '进阶选读：匹配、LCA、SCC、割点/桥；A* 是第 k 短游走。',
    '基础速记：sum(l,r)=prefix[r]-prefix[l-1]；prefix[0]=0。',
    '一维差分：d[l]+=v，d[r+1]-=v；对 d 求前缀和还原。',
    'gcd：std::gcd(a,b)；lcm 先除再乘，注意乘积范围。',
    '维护：编辑分类目录中的 cpp；同步 catalog.json，验证后重新生成 PDF。',
    '本册保留原变量与函数习惯；具体来源和修正记录见 template/README.md。',
]
y0=TOP-140
for line in intro:
    for s in wrap(line,10):draw(c,s,M,y0,10);y0-=15
    y0-=7
c.showPage()

furniture(2,'目录 / Contents')
draw(c,'目录',M,TOP,17,True);yy=TOP-25
for chapter,title in chapters.items():
    draw(c,title,M,yy,10,True);yy-=17
    for item in (x for x in items if x['path'].startswith(chapter+'/')):
        label=item['number']+' '+item['title']
        draw(c,label,M+7,yy,8.8)
        pn=str(item['page']);draw(c,pn,W-M-width(pn,8.8),yy,8.8)
        c.linkRect('',item['path'],(M,yy-2,W-M,yy+10),relative=0,thickness=0)
        yy-=12
    yy-=4
assert yy>BOTTOM,yy
c.showPage()
seen=set()
for number,page in enumerate(pages,3):
    title=' / '.join(chapters[k].split(' / ')[-1] for k in page['chapters'])
    furniture(number,title)
    for block in page['blocks']:
        yy=block['y'];chapter=block['chapter']
        if block['key']:
            c.bookmarkPage(block['key'])
            if chapter not in seen:
                c.addOutlineEntry(chapters[chapter],block['key'],0,False);seen.add(chapter)
            c.addOutlineEntry(block['title'],block['key'],1,False)
        draw(c,block['title'],M,yy,12,True);yy-=19
        for line in block['meta']:draw(c,line,M,yy,8.2);yy-=11
        yy-=5
        for line in block['code']:
            draw(c,line,M,yy,block['size']);yy-=block['leading']
        assert yy>=BOTTOM-1,(number,block['title'],yy)
    c.showPage()
c.save()
manifest={'pages':total,'a4_mm':[210,297],'font':'Embedded Consolas + SimSun',
          'templates':[{'path':x['path'],'page':x['page'],
            'sha256':hashlib.sha256((ROOT/x['path']).read_bytes()).hexdigest()} for x in items]}
(OUT/'pdf_manifest.json').write_text(json.dumps(manifest,ensure_ascii=False,indent=2),encoding='utf-8')
print(f'Generated {target}: {total} pages')
