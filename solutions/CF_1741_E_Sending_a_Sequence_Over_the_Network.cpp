#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const int M = 2005;
int trie[M][26];
int ed[M];
int tot = 0;

void solve()
{
    int n; cin>>n;
    vector<int> b(n+1);
    for(int i=1; i<=n; i++) cin>>b[i];

    vector<bool> dp(n+1,0);
    dp[0] = true;

    for(int i=1; i<=n; i++){
        if(i+b[i]<=n && dp[i-1]) dp[i+b[i]] = true;

        if(i-b[i]>=1 && dp[i-b[i]-1]) dp[i] = true;
    }

    if(dp[n]) cout<<"YES\n";
    else cout<<"NO\n";

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}