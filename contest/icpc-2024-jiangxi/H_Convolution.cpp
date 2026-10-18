#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e3+5;
ll a[N][N];
ll pre[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k,l; cin>>n>>m>>k>>l;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin>>a[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];
        }
    }

    ll ans=0;
    int H = n - k + 1;
    int W = m - l + 1;

    for(int i=1 ; i<=k ; i++){
        for(int j=1 ; j<=l ; j++){

            ll cur=pre[i+H-1][j+W-1]-pre[i-1][j+W-1]-pre[i+H-1][j-1]+pre[i-1][j-1];
            ans+=abs(cur);
        }
    }

    cout<<ans;
    
    return 0;
}