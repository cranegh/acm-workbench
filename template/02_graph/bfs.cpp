// BFS
// 无权图最短距离；O(n+m)
// 1-index，n<N；不可达为 -1；多测清空 g[1..n]
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 接口：bfs(n,st) 后直接读 d[v]，函数本身没有返回值。
// d[v] 是 st 到 v 最少经过的边数；st 为 0，不可达为 -1。
// 调用例（放在 solve 中）：
// g[1]={2}; g[2]={1,3}; g[3]={2};
// bfs(3,1); cout << d[3]; // 输出 2。
// 每组先清空 g[1..n] 再读边；bfs 会重置 d，可更换起点重复调用。
// 有向边只加 g[u].push_back(v)，无向边还要加反方向。
// 要求 1<=st<=n<N，所有邻点也在 1..n；只适用无权或等权图。
const int N = 200005;
vector<int> g[N];
int d[N];
void bfs(int n, int st){
    fill(d,d+n+1,-1);
    queue<int> q;
    q.push(st); d[st] = 0;
    while(!q.empty()){
        // 队列按距离从小到大处理，第一次发现 v 就得到最短距离。
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(d[v]!=-1) continue;
            // 入队时就标记，防止同一点被多个邻点重复加入。
            d[v] = d[u]+1;
            q.push(v);
        }
    }
}
