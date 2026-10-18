#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e6+9;
ll h[N],v[N],rec[N],stk[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>h[i]>>v[i];

    int top=0;
    for(int i=1 ; i<=n ; i++){
        while(top>0 && h[stk[top]]<h[i]){
            rec[i]+=v[stk[top--]];
        }
        stk[++top]=i;
    }

    top=0;
    for(int i=n ; i>=1 ; i--){
        while(top>0 && h[stk[top]]<h[i]){
            rec[i]+=v[stk[top--]];
        }
        stk[++top]=i;
    }

    ll ans=0;
    for(int i=1 ; i<=n ; i++) ans=max(ans,rec[i]);

    cout<<ans;
    
    return 0;
    
}