#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 2e5+9;
ll dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V,n; cin>>V>>n;

    for(int i=1 ; i<=n ; i++){
        int v; cin>>v;
        for(int j=V ; j>=v ; j--){
            dp[j]=max(dp[j],dp[j-v]+v);
        }
    }

    cout<<V-dp[V];

}