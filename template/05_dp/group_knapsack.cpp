// 分组背包
// 每组至多选一个物品，容量至多 m 的最大价值；O(m*总物品数)
// 0<=m<N；组号 1..z_max<105；体积 a>0，价值和不能溢出 ll
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e3+9;
struct w{
    int a,b;
};

ll dp[N];
vector<w> wp[105];

ll knapsack(int m, int z_max){
    fill(dp,dp+m+1,0);
    for(int i=1 ; i<=z_max ; i++){
        for(int j=m ; j>=0 ; j--){
            for(auto &c : wp[i]){
                if(j>=c.a){
                    dp[j]=max(dp[j],dp[j-c.a]+c.b);
                }
            }
        }
    }
    return dp[m];
}

// 沿用原用法：wp[z].push_back({x,y})，x 是体积，y 是价值。
// 先算出 z_max，再调用 knapsack(m,z_max)；多测先清空各组 wp。
// 保留原来的容量倒序写法，必须 a>0，保证 dp[j-a] 仍是上一组状态。
