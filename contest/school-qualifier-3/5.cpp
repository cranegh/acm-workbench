#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 1e7+5;

ll f[N];

ll qpow(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1) res = res*a%MOD;
        a = a*a%MOD;
        n/=2;
    }
    return res;
}

ll inv(ll x){
    return qpow(x,MOD-2)%MOD;
}

void solve()
{
    ll n; cin>>n;

    f[0] = 1;
    for(int i=1 ; i<=n ; i++){
        f[i] = f[i-1]*i%MOD;
    }

    ll ans = 0;
    for(int i=1 ; n-2*i+1>=0 ; i++){
        ans = (ans + f[n-i]*f[n-i]%MOD*inv(f[n-2*i+1])%MOD)%MOD;
    }

    cout<<ans;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}