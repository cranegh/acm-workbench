// 二维差分
// 离线矩形加，最终还原；修改 O(1)，还原 O(nm)
// 1-index，n+1,m+1<N；原数组用 update(i,j,i,j,aij) 加入
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
ll d[N][N],a[N][N];
void init(){ memset(d,0,sizeof(d)); memset(a,0,sizeof(a)); }
void update(int x1, int y1, int x2, int y2, ll v){
    d[x1][y1] += v; d[x2+1][y1] -= v;
    d[x1][y2+1] -= v; d[x2+1][y2+1] += v;
}
void build(int n, int m){
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+d[i][j];
        }
    }
}
