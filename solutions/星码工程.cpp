#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll a[N];
vector<int> g[N];
int ind[N];

ll dp[N];

int n,m; 

void topo_sort(){
    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(ind[i]==0){
            q.push(i);
            dp[i]=a[i];
        }
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for(auto & v : g[u]){
            dp[v]=max(dp[v],dp[u]+a[v]);
            if(--ind[v]==0) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        ind[v]++;
    }

    topo_sort();

    ll ans=0;
    for(int i=1 ; i<=n ; i++) ans=max(ans,dp[i]);
    
    cout<<ans;

    return 0;
}