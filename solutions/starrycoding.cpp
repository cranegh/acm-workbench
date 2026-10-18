#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

const int M =1010;
ll dp[M];
int T,m;

struct fl{
    int t,v;
}a[M];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    while(cin>>T>>m){
        if(T==0 && m==0 ) break;

        for(int i=1 ; i<=T ; i++) dp[i]=0;
         
        for(int i=1 ; i<=m ; i++){
            cin>>a[i].t>>a[i].v;
        }
    
        for(int i=1 ; i<=m ; i++){
            for(int j=T ; j>0 ; j--){
                if(j>=a[i].t) dp[j]=max(dp[j-a[i].t]+a[i].v,dp[j]);
            }
        }

        for(int i=1 ; i<=m ; i++){
            for(int j=T ; j>=0 ; j--){
                if(j>=a[i].t) dp[j]=max(dp[j],dp[j-a[i].t]);
            }
        }

        cout<<dp[T]<<'\n';
    }

    return 0;
}