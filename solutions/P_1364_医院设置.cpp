#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;

const int N = 110;
vector<ll> g[N];
ll popu[N];

ll min_dist=1e9+9;
int n; 

void bfs(int start)
{
    ll cur_dist = 0;
    ll dist[N]; for(int i=1 ; i<=n ; i++) dist[i]=-1;

    queue<int> q;
    q.push(start);
    dist[start]=0;
    
    while(!q.empty()){
        int cur_node = q.front();
        q.pop();

        for(int i=0 ; i<g[cur_node].size() ; i++) if(dist[g[cur_node][i]]==-1) q.push(g[cur_node][i]);
        for(int i=0 ; i<g[cur_node].size() ; i++) dist[g[cur_node][i]]=dist[cur_node]+1;

        cur_dist+=dist[cur_node]*popu[cur_node];
    }

    min_dist=min(min_dist,cur_dist);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        ll w,u,v; cin>>w>>u>>v;
        popu[i]=w;

        if(u!=0){
            g[i].push_back(u);
            g[u].push_back(i);
        }

        if(v!=0){
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }

    for(int i=1 ; i<=n ; i++){
        bfs(i);
    }

    cout<<min_dist;
    
    return 0;
}