#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e3+9;
const int M = 1e4+9;
const int MOD = 1e9+7;
ll dp[M],a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,w; cin>>n>>w;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    dp[0]=1;

    for(int j=1 ; j<=w ; j++){
        for(int i=1 ; i<=n ; i++){
            if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        }
    }

    cout<<dp[w];

    return 0;
}