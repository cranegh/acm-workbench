#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 13000;
int dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;

    for(int i=1 ; i<=n ; i++){
        int w,v; cin>>w>>v;
        for(int j=m ; j>=w ; j--){
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }

    cout<<dp[m];

    return 0;
    
}