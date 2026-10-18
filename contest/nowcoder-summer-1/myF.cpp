#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dp[N][N];

void solve()
{
    int n; cin>>n;
    vector<ll> a(n+1);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = -INF;
        }
    }

    for(int i=0 ; i<=n ; i++) dp[1][i] = a[1];

    for(int i=2 ; i<=n ; i++){
        for(int j=i-1 ; j>=1 ; j--){
            dp[i][j] = max(dp[i][j+1],dp[i-j][j]+a[i]);
        }
    }

    ll ans = dp[n][1];
    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}
