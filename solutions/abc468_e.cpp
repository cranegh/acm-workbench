#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

ll qpow(ll base, ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1) res = (res*base)%MOD;
        n/=2;
        base = (base*base)%MOD;
    }
    return res;
}

ll calinv(ll x){
    return qpow(x,MOD-2);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> A(n+1); for(int i=1 ; i<=n ; i++) cin>>A[i];
    
    vector<ll> pre(n+1,0);
    vector<ll> inv(n+1,0);
    vector<ll> weight(n+1,0);

    for(int i=1 ; i<=n ; i++) inv[i] = calinv(i);
    for(int i=1 ; i<=n ; i++) pre[i] = (pre[i-1] + inv[i])%MOD;

    weight[1] = pre[n];
    for(int i=1 ; i<n ; i++) weight[i+1] = (weight[i] - pre[i] + pre[n-i] + MOD)%MOD;

    ll ans = 0;
    for(int i=1 ; i<=n ; i++) ans = (ans + A[i]*weight[i])%MOD;

    cout<<ans<<'\n';

    return 0;
}