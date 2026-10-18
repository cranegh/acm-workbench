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
    dp[0]=1;

    for(int i=1 ; i<=n ; i++){
        int v; cin>>v;
        for(int j=m ; j>=v ; j--){
            dp[j]+=dp[j-v];
        }
    }

    cout<<dp[m];

    return 0;
    
}