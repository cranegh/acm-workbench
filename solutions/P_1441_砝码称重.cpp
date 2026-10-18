#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 25;
int w[N];
bool dp[100*N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>w[i];

    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += w[i];

    int ans = 0;
    for(int mask=0; mask<(1<<n); mask++){
        if(__builtin_popcount(mask) != m) continue;

        memset(dp,0,sizeof(dp));
        dp[0] = true;

        for(int i=1; i<=n; i++){
            if(mask & (1<<(i-1))) continue;
            for(int j=sum; j>=w[i]; j--){
                dp[j] |= dp[j-w[i]];
            }
        }

        int res = 0;
        for(int i=1; i<=sum; i++){
            if(dp[i]) res++;
        }

        ans = max(res,ans);

    }

    cout<<ans;

    return 0;
}