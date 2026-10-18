#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+9;
ll d[N];
bitset<N> vis;

struct edge{
    int v; ll w;

    bool operator < (const edge& u) const
    {
        if(w==u.w) return v<u.v;
        else return w>u.w;
    }
};

vector<edge> g[N];
priority_queue<edge> pq;

int n,m,s;
void dijksta(int st){
    memset(d,0x3f,sizeof(d));

    d[st]=0;
    pq.push({st,d[st]});

    while(pq.size()){
        int cur=pq.top().v; pq.pop();

        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto &[v,w] : g[cur]){
            if(!vis[v] && d[v]>d[cur]+w){
                d[v]=d[cur]+w;
                pq.push({v,d[v]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>s;

    for(int i=0 ; i<m ; i++){
        int u,v; ll w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    dijksta(s);

    for(int i=1 ; i<=n ; i++){
        if(d[i]==INF) cout<<-1<<' ';
        else cout<<d[i]<<' '; 
    }

    return 0;
}