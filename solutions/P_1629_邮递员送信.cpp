#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

struct edge{
    int v;
    ll w;
    bool operator < (const edge& u) const
    {
        return w==u.w ? v>u.v : w>u.w;
    }
};

const int N = 1e3+9;
vector<edge> g1[N];
vector<edge> g2[N];
ll d[N];

void dijkstra_1(int st){
    priority_queue<edge> pq;
    memset(d,0x3f,sizeof(d));
    bitset<N> vis;

    d[st]=0;
    pq.push({st,d[st]});

    while(!pq.empty()){
        int cur = pq.top().v; pq.pop();
        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto &[v,w] : g1[cur]){
            if(d[v]>d[cur]+w && !vis[v]){
                d[v]=d[cur]+w;
                pq.push({v,d[v]});
            }
        }

    }
}

void dijkstra_2(int st){
    priority_queue<edge> pq;
    memset(d,0x3f,sizeof(d));
    bitset<N> vis;

    d[st]=0;
    pq.push({st,d[st]});

    while(!pq.empty()){
        int cur = pq.top().v; pq.pop();
        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto &[v,w] : g2[cur]){
            if(d[v]>d[cur]+w && !vis[v]){
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
        int u,v; ll w;
        cin>>u>>v>>w;
        g1[u].push_back({v,w});
        g2[v].push_back({u,w});
    }
    
    dijkstra_1(1);

    ll ans=0;
    for(int i=2 ; i<=n ; i++){
        ans+=d[i];
    }

    dijkstra_2(1);
    for(int i=2 ; i<=n ; i++){
        ans+=d[i];
    }

    cout<<ans;

    return 0;
}