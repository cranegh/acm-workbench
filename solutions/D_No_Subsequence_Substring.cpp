#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+9;

int dp[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    string t; cin>>t;

    ll ans=0;

    for(int i=0 ; i<s.size() ; i++){
        for(int j=t.size()-1 ; j>=0 ; j--)
        {
            if(s[i]==t[j]){
                if(j==0) dp[1]=max(dp[1],i+1);
                else dp[j+1]=max(dp[j+1],dp[j]);
            }
        }
        ans+=i+1-dp[t.size()];
    }

    cout<<ans;


    return 0;
}