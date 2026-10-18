#include<iostream>
#define maxn 22
using namespace std;
long long f[maxn][maxn]={0};
int ctrl[maxn][maxn]={0},n,m,hx,hy;
int d[9][2]= {{0,0},{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main(){
    cin>>n>>m>>hx>>hy;
    for ( int i=0 ; i<9 ; i++){
        int tempx=hx+d[i][0];
        int tempy=hy+d[i][1];
        if(tempx>=0 && tempx<=n && tempy>=0 && tempy<=m)
        ctrl[tempx][tempy]=1;
    }
    f[0][0]=1-ctrl[0][0];
    for(int i=0 ; i<=n ; i++)
    for(int j=0 ; j<=m ; j++){
        if(ctrl[i][j]) continue;
        if(i!=0)f[i][j]+=f[i-1][j];
        if(j!=0)f[i][j]+=f[i][j-1];
    }
    cout<<f[n][m];
    return 0;
}