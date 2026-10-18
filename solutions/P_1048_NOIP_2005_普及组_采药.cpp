#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e3+9;
ll dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T,n; cin>>T>>n;

    for(int i=1 ; i<=n ; i++){
        int t,v; cin>>t>>v;
        for(int j=T ; j>=t ; j--){
            dp[j]=max(dp[j],dp[j-t]+v);
        }
    }

    cout<<dp[T];

}