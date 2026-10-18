#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int n,m;
int a[N];
int pre[N];
int dp[N];

int root(int x){
    if(pre[x] == x) return x;
    return pre[x] = root(pre[x]);
}

void merge(int u, int v){
    pre[root(u)] = root(v);
}

struct edge{
    int u,v;
    bool operator < (const edge& cur) const
    {
        return a[u]<a[cur.u];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    vector<edge> edges;

    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) pre[i] = i;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        if(a[u] == a[v]) merge(u,v);
        else{
            if(a[u] > a[v]) swap(u,v);
            edges.push_back({u,v});
        }
    }

    sort(edges.begin(),edges.end());
    dp[root(1)] = 1;

    for(auto[u,v] : edges){
        int x = root(u);
        int y = root(v);

        if(dp[x] == 0) continue;
        dp[y] = max(dp[y],dp[x] + 1); 
    }

    cout<<dp[root(n)];
    
    return 0;
}