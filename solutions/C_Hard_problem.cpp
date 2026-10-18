#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll c[N];
ll dp[N][2];
string s[N][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++) cin>>s[i][0];
    for(int i=1; i<=n; i++) s[i][1] = s[i][0];
    for(int i=1; i<=n; i++) reverse(s[i][1].begin(),s[i][1].end());
    memset(dp,0x3f,sizeof(dp));

    dp[0][0] = 0;
    dp[0][1] = 0;

    for(int i=1; i<=n; i++){
        if(s[i][0] >= s[i-1][0]) dp[i][0] = min(dp[i-1][0],dp[i][0]);
        if(s[i][0] >= s[i-1][1]) dp[i][0] = min(dp[i-1][1],dp[i][0]);

        if(s[i][1] >= s[i-1][0]) dp[i][1] = min(dp[i-1][0],dp[i][1]);
        if(s[i][1] >= s[i-1][1]) dp[i][1] = min(dp[i-1][1],dp[i][1]);
        if(dp[i][1] != INF) dp[i][1] += c[i];
    }

    ll ans = min(dp[n][0],dp[n][1]);
    if(ans == INF) ans = -1;
    cout<<ans;
    
    return 0;
}