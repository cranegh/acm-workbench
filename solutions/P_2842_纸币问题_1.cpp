#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e4+9;
int a[N],dp[N];
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,w; cin>>n>>w;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=w ; i++) dp[i]=INF;

    for(int i=1 ; i<=n ; i++){
        for(int j=a[i] ; j<=w ; j++){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }

    cout<<dp[w];

    return 0;
}