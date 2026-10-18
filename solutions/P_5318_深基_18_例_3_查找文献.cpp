#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
vector<int> g[N];
bitset<N> vis;

void dfs(int u){
    cout<<u<<" ";
    for(int v : g[u]){
        if(vis[v]) continue;
        vis[v] = true;
        dfs(v);
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout<<cur<<" ";
        for(int v : g[cur]){
            if(vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        sort(g[i].begin(),g[i].end());
    }

    vis[1] = true;
    dfs(1);
    cout<<'\n';

    vis.reset();

    vis[1] = true;
    bfs(1);
    cout<<'\n';
}