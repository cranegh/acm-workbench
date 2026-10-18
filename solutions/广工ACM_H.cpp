#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll dp[N][2],e[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>e[i];

    dp[1][0]=e[1];
    dp[1][1]=0;
    dp[2][0]=0;
    dp[2][1]=e[2];

    for(int i=3 ; i<=n ; i++){
        dp[i][0]=dp[i-1][1]+e[i];

        dp[i][1]=max(dp[i-2][1],dp[i-2][0])+e[i];
    }

    ll ans=max(dp[n][0],dp[n][1]);

    cout<<ans;

    return 0;

}
