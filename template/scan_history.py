from pathlib import Path
import re, json, hashlib

ROOT = Path(__file__).resolve().parent.parent
patterns = {
    'fenwick': r'lowbit', 'segment_tree': r'pushdown|maketag',
    'kmp': r'pi\[|kmp|KMP', 'manacher': r'Manacher|manacher|2\*C-i',
    'dsu': r'fa\[.*root|find\(fa\[', 'shortest_path': r'dijk|Astar|floyd',
    'scc_lca_bridge': r'tarjan|low\[|lca|LCA|dfn\[',
    'math': r'exgcd|qpow|prime|primes|inv\(',
    'dp': r'dp\[|f\[.*max|lower_bound',
    'geometry': r'cross\(|atan2|hypot', 'trie_z': r'trie|z_function|son\[',
}
files=[]
for p in sorted(ROOT.rglob('*')):
    if p.suffix.lower() not in ('.cpp','.cc','.cxx','.h','.hpp') or any(x in p.relative_to(ROOT).parts for x in ('template','.template_work','.git')):
        continue
    raw=p.read_bytes()
    for enc in ('utf-8-sig','gb18030','utf-16'):
        try: s=raw.decode(enc); break
        except UnicodeError: pass
    else: s=raw.decode('utf-8',errors='replace'); enc='replacement'
    files.append(dict(path=p.relative_to(ROOT).as_posix(),encoding=enc,lines=len(s.splitlines()),
        sha256=hashlib.sha256(raw).hexdigest(),tags=[k for k,v in patterns.items() if re.search(v,s)],
        bits=bool(re.search(r'#include\s*<bits/stdc\+\+\.h>',s)),
        ll='using ll = long long;' in s,io='ios::sync_with_stdio(0)' in s,
        vector='vector<' in s,lambdas=bool(re.search(r'\[&?\]\s*\(',s))))
out=ROOT/'template/history_inventory.json'
out.write_text(json.dumps(files,ensure_ascii=False,indent=2),encoding='utf-8')
print('Files:',len(files),'Lines:',sum(x['lines'] for x in files))
for k in ('bits','ll','io','vector','lambdas'): print(k,sum(x[k] for x in files))
for tag in patterns:
    matches=[x['path'] for x in files if tag in x['tags']]
    print('\n'+tag, len(matches)); print('\n'.join(matches[:45]))

