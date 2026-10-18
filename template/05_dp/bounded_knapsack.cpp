// 多重背包
// 二进制拆分数量限制；O(m * sum(log(cnt+1)))
// t>0，cnt>=0，m>=0；价值乘数量及总价值必须装入 ll
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 每种物品最多 cnt 件，求总容量不超过 m 时能取得的最大价值。
// item 中 t=单件体积，v=单件价值，cnt=最多可用件数。
// 调用例（放在 solve 中）：
// vector<item> a={{2,3,2},{3,5,1}};
// cout << knapsack(7,a); // 输出 11：第一种 2 件，第二种 1 件。
// 返回最大价值 ll，不返回选择方案；允许一件不选，所以结果至少为 0。
// 要求 m>=0、t>0、cnt>=0，容量数组可放入内存，价值运算不溢出 ll。
// 函数内部新建 dp，多测直接重新调用；输入物品数量不会被修改。
// 此处是“至多装 m”；恰好装满时要另改不可达初始化和转移判断。
struct item{ int t; ll v; int cnt; };
ll knapsack(int m, const vector<item>& a){
    // dp[j]：已处理物品、容量至多 j 的最大价值，初始都为 0。
    vector<ll> dp(m+1);
    for(auto [t,v,cnt] : a){
        // 再多也装不下的件数先去掉，且保证后面的 t*c 不超过 m。
        cnt = min(cnt,m/t);
        // 拆成 1、2、4 等大小的包和最后余数，每包当作一个 01 物品。
        // 例如 13 件拆为 1、2、4、6，可组合出 0..13 的任意件数。
        for(ll k=1 ; cnt>0 ; k*=2){
            int c = (int)min(k,(ll)cnt); cnt -= c;
            int w = t*c; ll val = v*c;
            // 容量倒序，避免同一个拆分包在本轮被重复使用。
            for(int j=m ; j>=w ; j--) dp[j] = max(dp[j],dp[j-w]+val);
        }
    }
    return dp[m];
}
