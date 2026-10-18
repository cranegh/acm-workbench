#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int n,s,far;
int dis[N],fa[N],flag[N];
vector<int> g[N];

void dfs(int u, int f){
    fa[u] = f;
    if(dis[u]>dis[far]) far = u;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(v==f || flag[v]) continue;
        dis[v] = dis[u]+1;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int A,B;
    dis[1] = 1; dfs(1,0); A = far;
    dis[far] = 0; dfs(far,0); B = far;
    int x = 0;
    for(int i=B ; i ; i=fa[i]){
        x++;
    }

    if((x/2)%2==0) cout<<"Second";
    else cout<<"First";

    return 0;
}