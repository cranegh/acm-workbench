// A* 第 k 短路
// 非负权图第 k 短游走，可重复点边；最坏 O((n+km) log(n+km))。
// 1<=n<N，1<=k<INT_MAX；边权>=0，所求答案<INF，所有距离用 ll。
// 建边：g1[a].push_back({b,l}); g2[b].push_back({a,l});
// 设好 s,t,k；若 s==t，先 k++ 排除空游走，然后 dijkstra(t); Astar(s);
// 答案在 ans 中，-1 表示本范围内不存在；多测清空 g1/g2。
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
int times[N]; // 补充：各点已弹出次数，防止含环时反复扩展而无法结束。

void dijkstra(int st)
{
    vis.reset(); // 补充初始化，允许重复调用。
    for(int i=1 ; i<=n ; i++) dist[i] = INF;
    dist[st] = 0;
    priority_queue<edge> pq;
    pq.push({st,dist[st]});

    while(!pq.empty()){
        int cur = pq.top().v; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = true;

        for(auto [v,l] : g2[cur]){
            // 先用减法判断范围，保证后面的 ll 加法安全。
            if(l>=INF-dist[cur]) continue;
            if(dist[cur] + l < dist[v]){
                dist[v] = dist[cur] + l;
                pq.push({v,dist[v]});
            }
        }
    }
}

void Astar(int st)
{
    ans = -1;
    cnt = 0;
    memset(times,0,sizeof(times));
    if(dist[st]==INF) return; // 补充：起点无法到终点时不用搜索。

    priority_queue<edge> pq;
    pq.push({st,dist[st]});

    while(!pq.empty()){
        int cur = pq.top().v;
        ll curl = pq.top().l;
        ll f = curl - dist[cur];

        pq.pop();
        // 第 k 短只需要每个点前 k 次弹出，零权环也能终止。
        if(times[cur]>=k) continue;
        times[cur]++;
        if(cur==t) cnt++;
        if(cnt==k){
            ans = curl;
            return;
        }

        for(auto [v,l] : g1[cur]){
            if(dist[v]==INF || times[v]>=k) continue;
            // curl 是估计总长，f 是已走长度；保持原来的 f+dist[v]+l。
            // 边权非负，分两步保证总和 <INF，不需要更宽的整数类型。
            if(l>=INF-f) continue;
            if(dist[v]>=INF-f-l) continue;
            pq.push({v,f+dist[v]+l});
        }
    }
}
