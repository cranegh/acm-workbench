#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 1e5+9;
vector<int> g[N];

int n,k;
int far=0;
int f[N];
ll dist[N];
bitset<N> vis;

void dfs(int u, int fa)
{
    f[u]=fa;
    for(int &v : g[u])
    {
        if(v==fa || vis[v]) continue;

        dist[v]=dist[u]+1;
        dfs(v,u);
    }
    if(dist[u]>dist[far]) far=u;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dist[1]=1; dfs(1,0); int A=far;
    dist[A]=0; dfs(A,0); int B=far;

    ll ans=n;
    for(int i=B,j=B ; i ; i=f[i]){
        while(dist[j]-dist[i]>k) j=f[j];

        ll x=max(dist[i],dist[B]-dist[j]);
        ans=min(ans,x);
    }
    
    for(int i=B ; i ; i=f[i])   vis[i]=true;
    
    for(int i=B ; i ; i=f[i]){
        dist[i]=0;
        far=0;
        dfs(i,f[i]);
        ans=max(ans,dist[far]);
    }

    cout<<ans;

}