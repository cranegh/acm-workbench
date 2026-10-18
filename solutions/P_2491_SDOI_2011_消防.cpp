#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 3e5+9;

int n;
ll s;
int far=0;
ll dist[N];
int f[N];
bitset<N> vis;

struct edge{
    int to;
    ll w;
};

vector<edge> g[N];

void dfs(int u, int fa)
{
    f[u]=fa;
    if(dist[u]>dist[far]) far=u;

    for(auto &[v,w] : g[u]){
        if(v==fa || vis[v]) continue;

        dist[v]=dist[u]+w;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>s;
    for(int i=1 ; i<n ; i++){
        int u,v; ll w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dist[1]=1; dfs(1,0); int A=far;
    dist[A]=0; dfs(A,0); int B=far;

    ll ans=n;
    for(int i=B,j=B ; i ; i=f[i]){
        while(dist[j]-dist[i]>s) j=f[j];

        ll x=max(dist[i],dist[B]-dist[j]);
        ans=min(x,ans);
    }

    for(int i=B ; i ; i=f[i]) vis[i]=true;

    for(int i=B ; i ; i=f[i]){
        dist[i]=0;
        far=i;
        dfs(i,f[i]);
        ans=max(dist[far],ans);
    }

    cout<<ans;

    return 0;
}