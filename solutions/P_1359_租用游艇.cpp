#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const int N = 205;
ll dp[N][N];

const ll INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    memset(dp,0x3f,sizeof(dp));

    for(int i=1 ; i<n ; i++){
        for(int j=i+1 ; j<=n ; j++){
            cin>>dp[i][j];
        }
    }

    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    cout<<dp[1][n];

    return 0;
}