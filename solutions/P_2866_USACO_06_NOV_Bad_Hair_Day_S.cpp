#include<iostream>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N],stk[N],obs[N],c[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>h[i];

    int top=0;
    for(int i=1 ; i<=n ; i++){
        while(top>0 && h[i]>=h[stk[top]]){
            obs[stk[top--]]=i;
        }
        stk[++top]=i;
    }

    for(int i=1 ; i<=n ; i++){
        if(obs[i]==0) obs[i]=n+1;
        c[i]=obs[i]-i-1;
    }

    ll ans=0;
    for(int i=1 ; i<=n ; i++) ans+=c[i];

    cout<<ans;
 
    return 0;
}
