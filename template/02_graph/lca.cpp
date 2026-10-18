// 倍增 LCA
// 树 / 森林最近公共祖先；预处理 O(n log n)，查询 O(log n)
// 1-index，n<N；每棵树取编号最小点为根；不同树返回 0
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// LCA 是两个点共同祖先中最深的点；适用于无向树或森林。
// 本模板每棵树以编号最小的点为根，build 不接受自定义根参数。
// 调用例（放在 solve 中）：
// g[1]={2,3}; g[2]={1}; g[3]={1}; g[4].clear(); build(4);
// cout << lca(2,3); // 输出 1；lca(2,4) 返回 0，表示不在同一棵树。
// 顺序：清空 g[1..n] -> 无向边存两次 -> build(n) -> 多次 lca。
// build 会重置查询状态；改边后必须重新 build，不能直接继续查询。
// 点编号必须为 1..n 且 n<N；图必须无环，不是一般图的公共祖先。
// 若增大 N，也要增大 LOG，使 2^LOG>最大可能深度。
const int N = 200005,LOG = 18;
vector<int> g[N];
// fa[j][v] 是 v 向上走 2^j 步的祖先，无祖先时为 0。
// dep[v] 是深度（根为 0）；bel[v] 是所在树的根，用于判断连通。
int fa[LOG][N],dep[N],bel[N];
void build(int n){
    fill(dep,dep+n+1,-1);
    for(int j=0 ; j<LOG ; j++) fill(fa[j],fa[j]+n+1,0);
    for(int st=1 ; st<=n ; st++){
        if(dep[st]!=-1) continue;
        queue<int> q; q.push(st); dep[st] = 0; bel[st] = st;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : g[u]){
                if(dep[v]!=-1) continue;
                dep[v] = dep[u]+1; bel[v] = st; fa[0][v] = u;
                // 走 2^j 步 = 先走 2^(j-1) 步，再走相同步数。
                for(int j=1 ; j<LOG ; j++) fa[j][v] = fa[j-1][fa[j-1][v]];
                q.push(v);
            }
        }
    }
}
int lca(int u, int v){
    if(bel[u]!=bel[v]) return 0;
    if(dep[u]<dep[v]) swap(u,v);
    int d = dep[u]-dep[v];
    // 先按深度差的二进制位跳，让 u、v 到达同一层。
    for(int j=0 ; j<LOG ; j++) if(d>>j&1) u = fa[j][u];
    if(u==v) return u;
    for(int j=LOG-1 ; j>=0 ; j--){
        // 只跳到仍不同的祖先；最后两点的父亲就是 LCA。
        if(fa[j][u]!=fa[j][v]) u = fa[j][u],v = fa[j][v];
    }
    return fa[0][u];
}
