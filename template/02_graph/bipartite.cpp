// 二分图染色
// 无向图二分性判定；O(n+m)
// 1-index，n<N；无向边加两次；覆盖不连通图
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 判断无向图能否分成两组，使每条边的两端分属不同组。
// 返回 true 时 color[v] 为 0 或 1；false 表示存在冲突（奇环）。
// false 时染色可能尚未完成，不要把所有 color 当作合法分组。
// 调用例（放在 solve 中）：
// g[1]={2}; g[2]={1,3}; g[3]={2};
// bool ok=bipartite(3); // true，color 为 0,1,0。
// 再加 g[1].push_back(3); g[3].push_back(1); 会得到 false。
// 每组先清空 g[1..n] 再读边；bipartite 会自动重置 color。
// 编号 1..n，n<N；无向边必须存两个方向，自环会判为 false。
const int N = 200005;
vector<int> g[N];
int color[N];
bool bipartite(int n){
    fill(color,color+n+1,-1);
    queue<int> q;
    for(int st=1 ; st<=n ; st++){
        // 每个未染色的连通块都单独开始，孤立点也会染色。
        if(color[st]!=-1) continue;
        color[st] = 0; q.push(st);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : g[u]){
                // ^1 在 0、1 之间切换；相邻点已同色就不可能合法。
                if(color[v]==-1){ color[v] = color[u]^1; q.push(v); }
                else if(color[v]==color[u]) return false;
            }
        }
    }
    return true;
}
