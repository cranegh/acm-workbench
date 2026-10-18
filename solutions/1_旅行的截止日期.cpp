#include<iostream>
#include<bitset>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
using ll=long long;

ll n,m,x,y,z;
const int N = 1e5+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dist[N];
bitset<N> vis;

struct edge{
    ll to,k,t;
};

struct node{
    ll to,dep;
    bool operator < (const node& u) const{
        return dep==u.dep ? to<u.to : dep>u.dep;
    }
};

vector<edge> g[N];

void dijkstra(ll st)
{
    memset(dist,0x3f,sizeof(dist));
    priority_queue<node> pq;
    dist[st]=0;
    pq.push({st,dist[st]});

    while(!pq.empty()){
        ll cur = pq.top().to; pq.pop();
        ll cur_dist=dist[cur];

        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto& [to,k,t] : g[cur]){

            ll cur_dep=(cur_dist+k-1)/k*k+t;
            if(cur_dep<dist[to]){
                dist[to]=cur_dep;
                pq.push({to,dist[to]});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>x>>y>>z;

    for(int i=0 ; i<m ; i++){
        ll a,b,k,t; cin>>a>>b>>k>>t;
        g[a].push_back({b,k,t});
        g[b].push_back({a,k,t});
    }

    dijkstra(x);

    if(dist[y]>z) cout<<"NO\n";
    else cout<<"YES\n";
  
}