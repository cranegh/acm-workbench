#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e4+9;
int dp[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int V,n,c; cin>>V>>n>>c;

    for(int i=1 ; i<=n ; i++){
        int m,v; cin>>m>>v;
        for(int j=c ; j>=v ; j--){
            dp[j]=max(dp[j],dp[j-v]+m);
        } 
    }

    if(dp[c]<V) cout<<"Impossible";
    else{
        int need=c;
        while(dp[need]>=V) need--;
        need++;
        cout<<c-need;
    }



    return 0;
    
}