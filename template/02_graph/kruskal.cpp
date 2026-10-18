// Kruskal
// 最小生成树 / 最小生成森林；排序 O(m log m)，并查集保留原路径压缩写法。
// e[1..m] 存边，1<=n<N、0<=m<N；边权为 int，总权值用 ll。
// 调用 kruskal(n,m)，返回 {是否连通,总权值}；不连通时权值为最小生成森林权值。
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3e5+5;
struct edge{
    int u,v,w;
    bool operator < (const edge &oth) const{
        return w<oth.w;
    }
}e[N];

int fa[N];

int root(int x)
{
    if(fa[x]==x) return x;
    else return fa[x] = root(fa[x]);
}

pair<bool,ll> kruskal(int n, int m)
{
    for(int i=1 ; i<=n ; i++) fa[i] = i;

    sort(e+1,e+m+1);

    ll tt = 0;
    int cnt = 0;
    for(int i=1 ; i<=m ; i++){
        int u = root(e[i].u);
        int v = root(e[i].v);

        if(u==v) continue;

        // 原题的零权跳过、礼物价格限制均属题目逻辑；普通 MST 直接计入边权。
        tt += e[i].w;
        fa[u] = v;
        cnt++;
    }
    return {cnt==n-1,tt};
}
// 多测覆盖 e[1..m] 即可。root 保留递归路径压缩；极深父链要留意栈空间。
