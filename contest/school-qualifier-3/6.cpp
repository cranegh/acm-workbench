#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,k,s; cin>>n>>k>>s;

    ll ans = (1+s)*s/2*k;
    cout<<ans;

    return;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}