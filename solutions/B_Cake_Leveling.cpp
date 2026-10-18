#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> h(n+1);
    vector<ll> pre(n+1);
    for(int i=1 ; i<=n ; i++) cin>>h[i];
    for(int i=1 ; i<=n ; i++) pre[i]=pre[i-1]+h[i];

    vector<ll> dp(n+1,0);
    dp[1]=h[1];
    for(int i=2 ; i<=n ; i++) dp[i]=min(dp[i-1],pre[i]/i);

    for(int i=1 ; i<=n ; i++) cout<<dp[i]<<" ";
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}