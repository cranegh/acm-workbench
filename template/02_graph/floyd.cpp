// Floyd
// 全源最短路；O(n^3)
// 1-index，n<N；无负环，边权及有限路径绝对值<INF/2；不可达 INF。
// 先设 n 并 init()，再加边，最后调用 floyd()。
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

// 修正原稿：INF 与 memset 的 0x3f 保持一致，便于准确判断不可达。
const ll INF = 0x3f3f3f3f3f3f3f3f;

const int N = 305;
ll d[N][N];

int n;

void init(){
    memset(d,0x3f,sizeof(d));
}

void floyd(){
    for(int i=1 ; i<=n ; i++) d[i][i]=0;

    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                // 补充可达判断：INF 加负边不能当作一条真实路径。
                if(d[i][k]!=INF && d[k][j]!=INF)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
// init 后加边：d[u][v]=min(d[u][v],w)；无向边加两次。
