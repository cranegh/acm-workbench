// 割点与桥
// 无向图 lowlink，支持重边；O(n+m)
// 1-index，n<N；每条无向边有唯一非负 id，两方向共用 id
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 割点：删去该点及其边后连通块数增加；桥：删去该边后块数增加。
// 只用于无向图；支持重边，点编号为 1..n 且 n<N。
// 每条无向边给唯一非负 id，同一条边的两个方向共用这个 id。
// 调用例（放在 solve 中）：
// for(int i=1;i<=3;i++) g[i].clear();
// g[1].push_back({2,0}); g[2].push_back({1,0});
// g[2].push_back({3,1}); g[3].push_back({2,1}); build(3);
// 此时 cut[2]=true，bridge 包含边号 0、1（顺序不保证）。
// build 无返回值；cut[v] 表示是否割点，bridge 保存所有桥的 id。
// 每组清空 g[1..n]、重新加边后调用 build；内部会重置工作数组。
// 若要输出桥的两个端点，读边时另外按 id 保存端点，凭 id 查回。
const int N = 200005;
vector<pair<int,int>> g[N]; // {邻点,边编号}
// dfn[u] 为首次访问时间；low[u] 为 u 的子树经树边和至多一条
// 非树边能到达的最小 dfn。low 越小，说明能绕回越早的祖先。
// fa[u] 为 DFS 父亲，pe[u] 为父边 id；根 fa=0、pe=-1。
// it[u] 为下一条待检查边；child[u] 为 DFS 树中直接孩子数。
int dfn[N],low[N],fa[N],pe[N],it[N],child[N],timer;
bool cut[N];
vector<int> bridge;
void build(int n){
    timer = 0; bridge.clear();
    for(int i=1 ; i<=n ; i++){
        dfn[i] = low[i] = fa[i] = it[i] = child[i] = 0;
        pe[i] = -1; cut[i] = false;
    }
    for(int st=1 ; st<=n ; st++){
        if(dfn[st]) continue;
        vector<int> stk = {st}; dfn[st] = low[st] = ++timer;
        while(!stk.empty()){
            int u = stk.back();
            if(it[u]<(int)g[u].size()){
                auto [v,id] = g[u][it[u]++];
                // 只跳过父边本身，不能跳过所有通往父亲的边（重边）。
                if(id==pe[u]) continue;
                if(!dfn[v]){
                    fa[v] = u; pe[v] = id; child[u]++;
                    dfn[v] = low[v] = ++timer; stk.push_back(v);
                }else low[u] = min(low[u],dfn[v]);
            }else{
                // 出栈相当于递归返回，u 的所有孩子已完成，low[u] 已确定。
                stk.pop_back(); int p = fa[u];
                // 根没有祖先；有至少两个 DFS 孩子时，删根才会分裂。
                if(!p){ cut[u] = child[u]>1; continue; }
                low[p] = min(low[p],low[u]);
                // 子树连父亲也绕不到，父边就是桥（严格大于）。
                if(low[u]>dfn[p]) bridge.push_back(pe[u]);
                // 非根父亲：子树绕不到父亲以上，删父亲会断开（可等于）。
                if(fa[p] && low[u]>=dfn[p]) cut[p] = true;
            }
        }
    }
}
