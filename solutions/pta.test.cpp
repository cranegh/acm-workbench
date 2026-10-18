#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 1e5+9;
int a[55][55];
int sum[55][55];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m,k; cin>>n>>m>>k;
    for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=m ; j++)
    cin>>sum[i][j];
    
    for(int i=1 ; i<=m ; i++)
    for(int j=1 ; j<=n ; j++)
    sum[i][j]+=sum[i][j-1]+sum[i-1][j];
    
    
    for(int i=1 ; i<=n-k+1 ; i++){
    for(int j=1 ; j<=m-k+1 ; j++)
    {
        int ans=sum[i+k-1][j+k-1]-sum[i-1][j+k-1]-sum[i+k-1][j-1]+sum[i-1][j-1];
        cout<<ans<<' ';
    }
    cout<<'\n';
    }


    return 0;
}