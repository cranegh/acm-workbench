"""Compile every template and run focused regression tests."""
from pathlib import Path
import argparse, hashlib, json, subprocess, shutil

ROOT=Path(__file__).resolve().parent
parser=argparse.ArgumentParser();parser.add_argument('--cxx',default='g++');args=parser.parse_args()
cxx=shutil.which(args.cxx) or args.cxx
work=ROOT.parent/'tools'/'tests'/'template'/'.work';work.mkdir(parents=True,exist_ok=True)
catalog=json.loads((ROOT/'catalog.json').read_text(encoding='utf-8'))
assert len(catalog)==42
for item in catalog:
    p=ROOT/item['path'];text=p.read_text(encoding='utf-8')
    assert '__int128' not in text and 'int128' not in text,(p,'wide integer forbidden')
    r=subprocess.run([cxx,'-std=c++17','-fsyntax-only',str(p)],capture_output=True,text=True)
    assert r.returncode==0,(p,r.stderr)
print('C++17 syntax: 42/42 PASS')

def build_run(src,name,input_text,expected=None):
    exe=work/(name+'.exe')
    r=subprocess.run([cxx,'-std=c++17','-O2',str(src),'-o',str(exe)],capture_output=True,text=True)
    assert r.returncode==0,(src,r.stderr)
    r=subprocess.run([str(exe)],input=input_text,text=True,capture_output=True,timeout=30)
    assert r.returncode==0,(src,r.stderr)
    if expected is not None:assert r.stdout==expected,(src,r.stdout,expected)

# These two files intentionally retain the original complete programs.
build_run(ROOT/'03_string/kmp.cpp','kmp_sample','ababa aba\n','1\n3\n0 0 1 ')
build_run(ROOT/'03_string/manacher.cpp','manacher_sample','abacaba\n','7')
build_run(ROOT/'03_string/manacher.cpp','manacher_even','abba\n','4')

# The graph restoration branch supplies a randomized differential regression.
graph_src=ROOT.parent/'tools'/'tests'/'template'/'graph_revision_tests.cpp'
if graph_src.exists():
    exe=work/'graph_revision_tests.exe'
    r=subprocess.run([cxx,'-std=c++17','-O1','-D_GLIBCXX_ASSERTIONS','-include','cassert',str(graph_src),'-o',str(exe)],capture_output=True,text=True)
    assert r.returncode==0,r.stderr
    r=subprocess.run([str(exe)],capture_output=True,text=True,timeout=180)
    assert r.returncode==0,(r.stdout,r.stderr)
    print('Historical graph differential tests: PASS')
else: print('Historical graph differential tests: SKIP')

report={'status':'PASS','template_count':42,'compiler':subprocess.check_output([cxx,'--version'],text=True).splitlines()[0],
 'checks':['42/42 independent C++17 syntax checks','KMP original program samples','Manacher original program samples',
           'historical graph randomized differential test: PASS' if graph_src.exists() else 'historical graph randomized differential test: SKIP (test source missing)',
           'no __int128/int128 in template sources'],
 'method':'Focused regression tests plus graph restoration differential suite. New snippets are syntax-checked; run them against problem-specific constraints before contest use.',
 'files':[{'path':x['path'],'sha256':hashlib.sha256((ROOT/x['path']).read_bytes()).hexdigest(),'compile':'PASS'} for x in catalog]}
(ROOT/'validation_report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf-8')
print('All validation checks passed.')
