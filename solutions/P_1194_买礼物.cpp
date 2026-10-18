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

void solve()
{
    int a,b; cin>>a>>b;
    for(int i=1 ; i<=b ; i++) fa[i] = i;

    int ii=1;
    for(int i=1 ; i<=b ; i++){
        for(int j=1 ; j<=b ; j++){
            cin>>e[ii].w;
            e[ii].u=i;
            e[ii].v=j;
            ii++;
        }
    }
    sort(e+1,e+ii);

    int tt = a*b;
    for(int i=1 ; i<=ii-1 ; i++){
        if(e[i].w==0) continue;
        int u = root(e[i].u);
        int v = root(e[i].v);

        if(u==v) continue;

        if(e[i].w>a) break;
        tt -= a-e[i].w;
        fa[u] = v;
    }
    cout<<tt;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}