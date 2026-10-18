#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s; cin>>s;
    int n=s.length();
    vector<vector<int>> dp(n,vector<int>(n,0));
    int l=0,r=n-1;

    for(int len=2 ; len<=n ; len++){
        for(int i=0 ; i<=n-len ; i++){
            int j=i+len-1;

            if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            else{
                dp[i][j]=1+min({dp[i+1][j-1],dp[i+1][j],dp[i][j-1]});
            }
        }
    }
    cout<<dp[0][n-1]<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}