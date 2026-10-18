#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int dp[205][205];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,M,T; cin>>n>>M>>T;

    for(int i=0 ; i<n ; i++){
        int m,t; cin>>m>>t;
        for(int j=M ; j>=m ; j--){
            for(int k=T ; k>=t ; k--){
                dp[j][k]=max(dp[j][k],dp[j-m][k-t]+1);
            }
        }
    }

    cout<<dp[M][T];
    
    return 0;
}