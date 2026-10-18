#include<iostream>

using namespace std;

const int N = 1e3+9,M = 1e4+9;
const int MOD = 1e9+7;
int a[N];
int dp[N];

int main(){
    int n,w; cin>>n>>w;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    dp[0]=1;
    for(int i=1 ; i<=n ; i++){
        for(int j=a[i] ; j<=w ; j++){
            dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        }
    }

    cout<<dp[w];

    return 0;
}