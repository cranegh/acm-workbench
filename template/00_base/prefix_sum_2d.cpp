// 二维前缀和
// 静态子矩形求和；预处理 O(nm)，查询 O(1)
// 先把原数组放 diff[1..n][1..m]，build 原地求前缀和；不能重复 build
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
ll diff[N][N];

void build(int n, int m){
    for(int i=0 ; i<=n ; i++) diff[i][0] = 0;
    for(int j=0 ; j<=m ; j++) diff[0][j] = 0;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            diff[i][j] -= diff[i-1][j-1];
            diff[i][j] += diff[i-1][j];
            diff[i][j] += diff[i][j-1];
        }
    }
}

ll query(int x1, int y1, int x2, int y2){
    return diff[x2][y2]-diff[x2][y1-1]
          -diff[x1-1][y2]+diff[x1-1][y1-1];
}
