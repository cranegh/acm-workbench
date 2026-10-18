#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const ll INF = 1e18;

struct edge{
    int v;
    ll w;
    bool operator < (const edge &u) const
    {
        return (w==u.w) ? v>u.v : w>u.w;
    }
};

const int N = 2e5+9;
vector<edge> g[N];
ll d[N];

void dijkstra(int st){
    memset(d,0x3f,sizeof(d));
    bitset<N> vis;
    priority_queue<edge> pq;

    d[st]=0;
    pq.push({st,d[st]});

    while(pq.size()){
        int cur = pq.top().v; pq.pop();

        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto &[v,w] : g[cur]){
            if(d[v]>d[cur]+w){
                d[v]=d[cur]+w;
                pq.push({v,d[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int u,v; ll w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    dijkstra(1);

    if(d[n]>=INF) cout<<-1;
    else cout<<d[n];

    return 0;
}