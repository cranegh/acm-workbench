#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 110;
int a[N][N],prefix[N][N];

int main(){
    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=m ; j++)
    cin>>a[i][j];

    for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=m ; j++)
    {
    prefix[i][j]+=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
    }

    int ans=0,cnt=0;
    for(int d=1 ; d<=n ; d++)
    for(int x=1 ; x+d-1<=n ; x++)
    for(int y=1 ; y+d-1<=m ; y++)
    {
        int xx=x+d-1,yy=y+d-1;
        cnt=prefix[xx][yy]-prefix[x-1][yy]-prefix[xx][y-1]+prefix[x-1][y-1];
        if(cnt==d*d) ans=d;
    }

    cout<<ans;
}