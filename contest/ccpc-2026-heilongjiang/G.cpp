#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

void solve()
{
    ll x; cin>>x;

    ll ans = 1;
    for(int i=1 ; i<x ; i++) ans = ans*10%MOD;
    ans=ans*x%MOD;

    cout<<ans;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}