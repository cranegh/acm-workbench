#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N],stk[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,k; cin>>n>>k;
    
    for(int i=1 ; i<=n ; i++) cin>>h[i];

    int top=0;
    ll ans=0;
    for(int i=1 ; i<=n ; i++){
        while(h[i]>h[stk[top]]){
            if(top==0) break;

            ll h_bottom=h[stk[top]];
            int left = stk[--top];
            ll width = i-left-1;

            ll cur=(min(h[i],h[left])-h_bottom)*width;
            if(cur>=0) ans+=cur;

        }
        stk[++top]=i;
    }

    cout<<ans;
    
    return 0;
}