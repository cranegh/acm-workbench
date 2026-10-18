#include<iostream>

using namespace std;

int dp[20][20];

int main(){
    int n; cin>>n;
    for(int i=0 ; i<=n ; i++)
    for(int j=0 ; j<=n ; j++){
        if(i==0) dp[i][j]=1;
        else if(j==0) dp[i][j]=dp[i-1][j+1];
        else dp[i][j]=dp[i][j-1]+dp[i-1][j+1];
    }

    cout<<dp[n][0];

    return 0;
}