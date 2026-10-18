// 迭代 DFS
// 遍历、生成树父亲与逆序树 DP；O(n+m)
// 1-index，n<N；仅遍历 st 所在可达部分；多测清空 g
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 用栈代替递归遍历；点编号为 1..n，1<=st<=n<N。
// dfs(n,st) 无返回值，结果在 order 和 fa 中。
// order 保存处理顺序，保证搜索树上的父亲排在孩子前面。
// fa[v] 为搜索树父亲；根的父亲为 0，不可达点为 -1。
// 调用例（放在 solve 中）：
// g[1]={2,3}; g[2]={1}; g[3]={1}; dfs(3,1);
// cout << fa[2]; // 输出 1；order 为 {1,3,2}。
// 树 DP 可倒序遍历 order，让所有孩子先算好，再更新父亲。
// 每组先清空 g[1..n] 再读边；dfs 会清空 order、重置 fa。
// 无向边存两次；只处理 st 可达部分，一般图得到一棵搜索树。
// 一般图的 order 不保证与逐条边递归 DFS 的顺序相同。
const int N = 200005;
vector<int> g[N],order;
int fa[N];
void dfs(int n, int st){
    fill(fa,fa+n+1,-1); order.clear();
    vector<int> stk = {st}; fa[st] = 0;
    while(!stk.empty()){
        int u = stk.back(); stk.pop_back();
        order.push_back(u);
        for(int v : g[u]){
            if(fa[v]!=-1) continue;
            // 入栈就确定父亲，避免环造成重复入栈；后入栈者先处理。
            fa[v] = u; stk.push_back(v);
        }
    }
}
// 树 DP 按 order 逆序处理；一般图这里只给出一棵搜索树。
