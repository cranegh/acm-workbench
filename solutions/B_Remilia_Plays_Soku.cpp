#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,x1,x2,k; cin>>n>>x1>>x2>>k;
    
    if(x1>x2) swap(x1,x2);
    ll d1 = abs(x1-x2);
    ll d2 = abs(x1+n-x2);
    
    ll ans = min(d1,d2)+k;
    if(n<=3) ans = 1;

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}