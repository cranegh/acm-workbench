#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<int> g[N];
ll a[N];
ll sum[N];
ll sz[N];
ll f[N];

void dfs(int cur, int fa)
{
    sum[cur] = a[cur];
    sz[cur] = 1;

    bool isleaf = true;
    ll min_f = INF;

    for(int &x : g[cur]){
        if(x==fa) continue;

        isleaf = false;

        dfs(x,cur);

        sum[cur] += sum[x];
        sz[cur] += sz[x];
        min_f = min(min_f,f[x]);
    }

    ll avg = sum[cur]/sz[cur];

    if(isleaf) f[cur] = avg;
    else f[cur] = min(avg,min_f);

}

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=n ; i++) g[i].clear();

    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1 ; i<=n ; i++) cout<<f[i]<<" ";
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}