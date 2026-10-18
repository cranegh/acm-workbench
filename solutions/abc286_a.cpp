#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;
int a[N];
int ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;

    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=0; i<=q-p; i++){
        ans[r+i] = a[p+i];
        ans[p+i] = a[r+i];
    }

    for(int i=1; i<=n; i++){
        if(!ans[i]) ans[i] = a[i]; 
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";

}