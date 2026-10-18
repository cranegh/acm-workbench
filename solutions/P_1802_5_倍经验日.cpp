#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e3+9;
ll dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    for(int i=1 ; i<=n ; i++){
        int a,b,c; cin>>a>>b>>c;
        for(int j=m ; j>=0 ; j--){
            if(j>=c) dp[j]=max(dp[j]+a,dp[j-c]+b);
            else dp[j]+=a;
        } 
    }

    cout<<5*dp[m];

}