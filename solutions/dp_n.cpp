#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 410;
ll a[N];
ll dp[N][N];
ll pre[N];

ll sum(int l, int r){
    return pre[r]-pre[l-1];
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) pre[i] = pre[i-1]+a[i];

    memset(dp,0x3f,sizeof(dp));
    for(int i=1; i<=n; i++) dp[i][i] = 0;

    for(int len=2; len<=n; len++){
        for(int l=1; l+len-1<=n; l++){
            int r = l+len-1;
            for(int k=l; k+1<=r; k++){
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+sum(l,r));
            }
        }
    }
    cout<<dp[1][n];

    return 0;
}