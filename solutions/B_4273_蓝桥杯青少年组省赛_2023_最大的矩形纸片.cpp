#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N],ans[N],stk[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    
    for(int i=1 ; i<=n ; i++) cin>>h[i];
    h[0]=-1,h[n+1]=-1;

    int top=0;
    ll s=0;
    for(int i=1 ; i<=n ; i++){
        while(h[i]<h[stk[top]]){
            ll cur = stk[top--];
            ll width = i-stk[top]-1;
            s=max(s,width*h[cur]);
        }
        stk[++top]=i;
    }
        
    cout<<s<<'\n';
    
    return 0;
    
}