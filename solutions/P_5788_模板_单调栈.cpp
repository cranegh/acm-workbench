#include<iostream>

using namespace std;
using ll = long long;

const int N = 3e6+9;
ll a[N],stk[N],ans[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    int top=0;
    for(int i=1 ; i<=n ; i++){
        while(top>0 && a[i]>a[stk[top]]){
            ans[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }

    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<' ';

    return 0;
}
