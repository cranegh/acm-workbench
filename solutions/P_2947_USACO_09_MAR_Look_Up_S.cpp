#include<iostream>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll h[N],stk[N],ans[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>h[i];

    int top=0;
    for(int i=1 ; i<=n ; i++){
        while(top>0 && h[i]>h[stk[top]]){
            ans[stk[top--]]=i;
        }

        stk[++top]=i;
    }

    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<'\n';


    return 0;
}
