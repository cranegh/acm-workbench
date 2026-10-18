// 01 背包
// 每件物品至多一次，容量至多 T 的最大价值；总复杂度 O(nT)
// 0<=T<N，t>=0；dp 全部清 0，答案 dp[T]；价值和不能溢出 ll
#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e3+9;
ll dp[N];

// 把原来读到一件物品后的更新单独拿出来，仍用原 dp 和倒序循环。
void add_item(int T, int t, int v){
    for(int j=T ; j>=t ; j--){
        dp[j]=max(dp[j],dp[j-t]+v);
    }
}

// 原用法：
// int T,n; cin>>T>>n;
// fill(dp,dp+T+1,0); // 多测必须清空
// for(int i=1 ; i<=n ; i++){
//     int t,v; cin>>t>>v;
//     add_item(T,t,v);
// }
// cout<<dp[T];
// 恰好装满时 dp[0]=0，其余置负 INF；转移前必须判断 dp[j-t] 可达。
