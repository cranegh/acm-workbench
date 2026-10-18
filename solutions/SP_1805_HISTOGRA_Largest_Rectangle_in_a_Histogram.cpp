#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N],ans[N],stk[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n;
    while(cin>>n){
        if(n==0) break;

        for(int i=1 ; i<=n ; i++) cin>>h[i];
        for(int i=1 ; i<=n ; i++) ans[i]=0;

        int top=0;
        for(int i=1 ; i<=n ; i++){
            while(top>0 && h[i]<h[stk[top]]){
                ans[stk[top]]+=(i-stk[top]);
                top--;
            }
            stk[++top]=i;
        }
        for(int i=1 ; i<=top ; i++) ans[stk[i]]+=(stk[top]-stk[i]+1);
        
        top=0;
        for(int i=n ; i>=1 ; i--){
             while(top>0 && h[i]<h[stk[top]]){
                ans[stk[top]]+=(stk[top]-i);
                top--;
            }
            stk[++top]=i;
        }
        for(int i=1 ; i<=top ; i++) ans[stk[i]]+=(stk[i]-stk[top]+1);

        for(int i=1 ; i<=n ; i++) ans[i]--;

        ll s=0;
        for(int i=1 ; i<=n ; i++){
            s=max(s,ans[i]*h[i]);
        }
        
        cout<<s<<'\n';
        
    }
    
    return 0;
    
}