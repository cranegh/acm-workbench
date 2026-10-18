#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3e5+9;
int dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    dp[0]=0;
    for(int i=1 ; i<=m ; i++){
        int v,w; cin>>v>>w;
        for(int j=n ; j>=v ; j--){
            dp[j]=max(dp[j],dp[j-v]+v*w);
        }
    }

    cout<<dp[n];

}