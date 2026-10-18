#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N],b[N],c[N];
ll dp[N][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i]>>c[i];

    for(int i=1; i<=n; i++){
        dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c[i];
    }

    ll ans = 0;
    for(int i=0; i<3; i++){
        ans = max(ans,dp[n][i]);
    }

    cout<<ans;
    
    return 0;
}