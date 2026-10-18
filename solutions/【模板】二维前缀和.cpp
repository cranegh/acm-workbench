#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e3+5;
int a[N][N],d[N][N];
ll prefix[N][N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m,q; cin>>n>>m>>q;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            cin>>a[i][j];
        }
    }

    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            d[i][j]+=a[i][j];
            d[i+1][j]-=a[i][j];
            d[i][j+1]-=a[i][j];
            d[i+1][j+1]+=a[i][j];
        }
    }
    
    while(q--){
        int x1,y1,x2,y2,v; cin>>x1>>y1>>x2>>y2>>v;
        d[x1][y1]+=v;
        d[x1][y2+1]-=v;
        d[x2+1][y1]-=v;
        d[x2+1][y2+1]+=v;
    }

    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=m ; j++){
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+d[i][j];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
        cout<<ans<<'\n';
    }
    return 0;
}