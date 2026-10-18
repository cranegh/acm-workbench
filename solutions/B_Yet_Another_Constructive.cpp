#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,k,m; cin>>n>>k>>m;
    if(k>m){
        cout<<"NO\n";
        return;
    }else{
        cout<<"YES\n";
        for(int i=1 ; i<=k-1 ; i++) cout<<1<<" ";
        cout<<m-k+1<<" ";
        for(int i=1 ; i<=n-k ; i++) cout<<1<<" ";
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}