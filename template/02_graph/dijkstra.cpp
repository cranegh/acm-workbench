// Dijkstra
// 非负权单源最短路；O((n+m) log(m+2))
// 1-index，n<N；边权>=0、所需距离<INF；不可达 INF；多测清空 g。
// 保留原函数名 dijksta：设好 n，建边 g[u].push_back({v,w})，调用 dijksta(s)。
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
    vis.reset(); // 原稿只跑一次；这里补充清空，方便重复调用。
    while(pq.size()) pq.pop();

    d[st]=0;
    pq.push({st,d[st]});

    while(pq.size()){
        int cur=pq.top().v; pq.pop();

        if(vis[cur]) continue;
        vis[cur]=true;

        for(auto &[v,w] : g[cur]){
            // 先判断减法，避免 d[cur]+w 溢出；距离 >=INF 不在本模板范围内。
            if(w>=INF-d[cur]) continue;
            if(!vis[v] && d[v]>d[cur]+w){
                d[v]=d[cur]+w;
                pq.push({v,d[v]});
            }
        }
    }
}
