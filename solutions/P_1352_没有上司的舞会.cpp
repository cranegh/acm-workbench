#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 6000+5;
int w[N];
vector<int> g[N];
int ind[N];
ll dp[N][2];

void dfs(int u, int fa)
{
    dp[u][0] = 0, dp[u][1] = w[u];
    for(int v : g[u]){
        if(v!=fa){
            dfs(v,u);
            dp[u][0] += max(dp[v][1],dp[v][0]);
            dp[u][1] += dp[v][0];
        }
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>w[i];

    for(int i=1 ; i<n ; i++){
        int l,k; cin>>l>>k;
        ind[l]++;
        g[k].push_back(l);
    }

    int root = 1;
    for(int i=1 ; i<=n ; i++) if(ind[i]==0) root = i;
    dfs(root,0);

    ll ans = max(dp[root][0],dp[root][1]);

    cout<<ans;


}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}