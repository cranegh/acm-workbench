#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll C(ll k){
    return k*(k-1)/2;
}

void solve()
{
    ll n,m; cin>>n>>m;

    ll ans = 0;
    if(m<=n-1) ans = C(m+1)-m;
    else ans = C(n)-m;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}