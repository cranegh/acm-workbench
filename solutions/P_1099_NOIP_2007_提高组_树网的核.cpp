#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

struct edge{
    int v;
    ll w;
};

const int N = 5e5+9;
vector<edge> g[N];
ll dist[N];
ll f[N];
bitset<N> vis;

ll far=0;

void dfs(int cur, int fa)
{
    f[cur]=fa;
    if(dist[cur]>dist[far]) far=cur;

    for(auto &[v,w] : g[cur]){
        if(v==fa || vis[v]) continue;

        dist[v]=dist[cur]+w;
        dfs(v,cur);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,s; cin>>n>>s;
    for(int i=1 ; i<n ; i++){
        int p,q; ll d;
        cin>>p>>q>>d;
        g[p].push_back({q,d});
        g[q].push_back({p,d});
    }

    dist[1]=1; dfs(1,0); int A=far;
    dist[A]=0; dfs(A,0); int B=far;

    for(int i=B ; i ; i=f[i]) vis[i]=true;

    ll cur_ans=dist[B];
    for(int i=B,j=B ; i ; i=f[i]){
        while(dist[j]-dist[i]>s) j=f[j];

        ll x=max(dist[i],dist[B]-dist[j]);

        cur_ans=min(x,cur_ans);
    }


    ll ans=cur_ans;
    for(int i=B; i ; i=f[i]){
        far=i;
        dist[i]=0;
        dfs(i,f[i]);
        ans=max(ans,dist[far]);
    }


    cout<<ans;

    return 0;
}