#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    int m = 2*n;
    vector<int> a(m);
    for(int i=0 ; i<m ; i++) cin>>a[i];
    vector<ll> first(n,-1);
    vector<ll> dp(m,0);

    dp[0] = 1;
    first[a[0]-1] = 0; 
    for(int i=1 ; i<m ; i++){
        dp[i] = dp[i-1]+1;
        if(first[a[i]-1]==-1) first[a[i]-1] = i;
        else if(first[a[i]-1]!=-1){
            if(first[a[i]-1] == 0) dp[i] = max(dp[i],(i+1ll)*(i+1));
            else dp[i] = max(dp[i],dp[first[a[i]-1]-1]+(i+1-first[a[i]-1])*(i+1-first[a[i]-1]));
        }
    }

    cout<<dp[m-1]<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T=1; cin>>T;
    while(T--) solve();

    return 0;
}