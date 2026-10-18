#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1010;
const ll INF = 0x3f3f3f3f3f3f3f3f;

bitset<N> vis;

int n,m; 
int s,t,k;

struct edge{
    int v;
    ll l;
    bool operator < (const edge& u) const
    {
        return l>u.l;
    }
};

ll dist[N];
vector<edge> g1[N];
vector<edge> g2[N];
ll ans = -1;
int cnt = 0;

void dijkstra(int st)
{
    for(int i=1 ; i<=n ; i++) dist[i] = INF;
    dist[st] = 0;
    priority_queue<edge> pq;
    pq.push({st,dist[st]});

    while(!pq.empty()){
        int cur = pq.top().v; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = true;

        for(auto [v,l] : g2[cur]){

            if(dist[cur] + l < dist[v]){
                dist[v] = dist[cur] + l;
                pq.push({v,dist[v]});
            }
        }

    }
    
}

void Astar(int st)
{
    priority_queue<edge> pq;
    pq.push({st,dist[st]});

    while(!pq.empty()){
        int cur = pq.top().v;
        ll curl = pq.top().l;
        ll f = curl - dist[cur];

        pq.pop();
        if(cur==t) cnt++;
        if(cnt==k){
            ans = curl;
            return;
        }

        for(auto [v,l] : g1[cur]){

            pq.push({v,f+dist[v]+l});
        }

    }
    
}

void solve()
{
    cin>>n>>m;

    for(int i=0 ; i<m ; i++){
        int a,b,l; cin>>a>>b>>l;
        g1[a].push_back({b,l});
        g2[b].push_back({a,l});
    }

    cin>>s>>t>>k;
    if(s==t) k++;
    dijkstra(t);

    Astar(s);

    cout<<ans;

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}