// 拓扑排序
// 有向图判环、DAG 处理顺序；O(n+m)
// 1-index，n<N；建边 u->v 时同时 ind[v]++，调用 topo_sort()。
// ans_sort.size()==n 表示无环；函数会消耗 ind，重复调用前要重新统计入度。
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;

const int N = 5e3+9;
vector<int> g[N];
int ind[N];

vector<int> ans_sort;

int n,m;

void topo_sort(){
    ans_sort.clear(); // 补充初始化：重复使用时清空上次答案。
    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(ind[i]==0) q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        ans_sort.push_back(u);

        for(auto & v : g[u]){
            if(--ind[v]==0) q.push(v);
        }
    }
}
// 多测先清空 g[1..n]、ind[1..n]，然后重新建图和统计入度。
