#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const ll MOD = 998244353;

ll qpow(ll a, ll n){
    ll res = 1;
    while(n>0){
        if(n&1) res = (res*a%MOD);
        n /= 2;
        a = (a*a)%MOD;
    }
    return res;
}

ll getf[N];
ll inv[N];
void init(){
    getf[1] = 1;
    for(int i=2; i<N; i++){
        getf[i] = (getf[i-1]*i)%MOD;
    }

    for(int i=1; i<N; i++){
        inv[i] = qpow(i,MOD-2);
    }
}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    
    vector<ll> pre(n+1,0);
    for(int i=1; i<=n; i++) pre[i] = (pre[i-1] + a[i-1])%MOD;
    vector<ll> s(n+1,0);

    for(int i=1; i<n; i++){
        ll res = (pre[n] - pre[i] + MOD)%MOD;
        res = (res - ((n-i)*a[i-1]%MOD) + MOD)%MOD;
        res = (res * getf[n-1])%MOD;
        res = (res * inv[n-i])%MOD;
        s[i] = res;
    }

    ll sum = 0;
    for(int i=1; i<=n-1; i++) sum = (sum + s[i])%MOD;

    cout<<sum<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    init();

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}