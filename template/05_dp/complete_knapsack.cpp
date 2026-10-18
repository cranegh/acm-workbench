// 完全背包（方案计数，保留原 P1832 的状态和转移）
// 每种体积可以使用无限次，求恰好凑出 n 的组合数；O(种类数*n)
// 0<=n<N，pri 中体积必须>0；同体积不要重复加入，所有 dp 状态须在 ll 内
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

vector<int> pri;
const int N = 1e3+9;
ll dp[N];
int n;

// pri 沿用原变量名：原题存素数，这里可以填任意允许使用的正体积。
// 原题的素数判断、读入和输出去掉，背包循环照原样保留。
void knapsack(){
    fill(dp,dp+n+1,0);
    dp[0]=1;
    for(int i=0 ; i<pri.size() ; i++){
        for(int j=pri[i] ; j<=n ; j++){
            dp[j]+=dp[j-pri[i]];
        }
    }
}

// 用法：n=5; pri={2,3}; knapsack(); cout<<dp[n]; // 1 种：2+3
// dp[j] 表示已枚举体积组成 j 的方案数；外层体积、内层正序。
// 正序使本种体积可以反复用；外层枚举种类避免把 2+3、3+2 重复计数。
// 若题目要求取模，在这条加法转移中按题意取模。
