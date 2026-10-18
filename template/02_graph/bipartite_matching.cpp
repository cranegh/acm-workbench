// 二分图最大匹配
// 增广路求最大匹配数；O(n左*m)
// 左右分别 1..n、1..m，均<N；只存左到右边；递归深度 O(n)
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 从已知二分图中选最多的边，要求任意两条选中边不共用端点。
// 左侧编号 1..n，右侧另从 1..m 编号；两侧同号不是同一个点。
// 只存左到右边 g[u].push_back(v)，这里不要加入反向边。
// 调用例（放在 solve 中）：
// g[1]={1,2}; g[2]={1}; cout << matching(2,2); // 输出 2。
// 结束后 match[1]=2、match[2]=1；match[v]=0 表示右点 v 未匹配。
// 每组先清空左侧 g[1..n] 再读边，最后调用 matching(n,m)。
// matching 会清空 match、vis；新增边后也可重新调用，重新求解。
// 要求 n,m<N；边必须跨两侧。递归深度可能达到左侧点数。
const int N = 2005;
vector<int> g[N];
// vis[v] 记录右点 v 最近在哪一轮增广中被访问，tag 是本轮编号。
int match[N],vis[N];
// 尝试给左点 u 找到配偶；成功返回 true，并修改沿途的匹配。
bool dfs(int u, int tag){
    for(int v : g[u]){
        if(vis[v]==tag) continue;
        vis[v] = tag;
        // 右点空闲就直接占用；否则尝试让它的旧配偶换一个右点。
        // 只有后续换位成功，才把当前 v 改配给 u，不会丢失旧匹配。
        if(!match[v] || dfs(match[v],tag)){
            match[v] = u; return true;
        }
    }
    return false;
}
int matching(int n, int m){
    fill(match,match+m+1,0); fill(vis,vis+m+1,0);
    int ans = 0;
    // 每个左点各尝试一次；本轮成功就使匹配边数增加 1。
    for(int u=1 ; u<=n ; u++) ans += dfs(u,u);
    return ans;
}
