// 强连通分量
// Kosaraju 迭代版；O(n+m)
// 1-index，n<N；加边同时 g[u].push_back(v)、rg[v].push_back(u)
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 有向图中，能互相到达的一组点构成一个强连通分量。
// scc(n) 无返回值；cnt 是分量数，bel[v] 是点 v 所属编号（1..cnt）。
// bel[u]==bel[v] 表示互相可达；孤立点也单独算一个分量。
// 调用例（放在 solve 中）：
// for(int i=1;i<=3;i++){ g[i].clear(); rg[i].clear(); }
// auto add=[&](int u,int v){ g[u].push_back(v); rg[v].push_back(u); };
// add(1,2); add(2,1); add(2,3); scc(3);
// 此时 cnt=2，bel[1]==bel[2]，bel[2]!=bel[3]。
// 每组先清空 g、rg 的 1..n，再同时建立原图和反图，最后 scc(n)。
// scc 会重置所有工作数组；要求点编号为 1..n，n<N。
// 缩点：原边 u->v 且 bel[u]!=bel[v] 时，连 bel[u]->bel[v]。
// 缩点图一定是 DAG；重复边是否去重由后续题意决定。
const int N = 200005;
// g 为原图，rg 为所有边反向的图；order 最初保存 DFS 完成顺序。
vector<int> g[N],rg[N],order;
int vis[N],bel[N],cnt;
void scc(int n){
    fill(vis,vis+n+1,0); fill(bel,bel+n+1,0);
    order.clear(); cnt = 0;
    for(int st=1 ; st<=n ; st++){
        if(vis[st]) continue;
        // 栈中 {u,i} 模拟递归：u 下一次要检查的是第 i 条出边。
        vector<pair<int,int>> stk = {{st,0}}; vis[st] = 1;
        while(!stk.empty()){
            int u = stk.back().first;
            int &i = stk.back().second;
            if(i==(int)g[u].size()){
                // 必须等所有出边处理完再记 u，这是“退出”顺序。
                order.push_back(u); stk.pop_back(); continue;
            }
            int v = g[u][i++];
            if(!vis[v]){ vis[v] = 1; stk.push_back({v,0}); }
        }
    }
    // 按退出顺序倒序，在反图遍历；每次新起点恰好找到一个分量。
    // 反图中遇到已分配 bel 的点就不再进入，避免跨入已处理分量。
    reverse(order.begin(),order.end());
    for(int st : order){
        if(bel[st]) continue;
        vector<int> stk = {st}; bel[st] = ++cnt;
        while(!stk.empty()){
            int u = stk.back(); stk.pop_back();
            for(int v : rg[u]){
                if(!bel[v]){ bel[v] = cnt; stk.push_back(v); }
            }
        }
    }
}
