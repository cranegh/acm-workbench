#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const int N = 1e7+9;
const int MOD = 1e9+7;
ll f[N];

ll qpow(ll a , ll n){
    ll res=1;
    while(n>0){
        if(n%2==1) res=res*a%MOD;
        a=a*a%MOD;
        n/=2;
    }
    return res;
}

ll inv(ll x){
    return qpow(x,MOD-2);
}

void init(){
    f[0]=1;
    for(int i=1 ; i<=N ; i++) f[i]=i*f[i-1]%MOD;
}

ll c(ll n , ll m){
    return f[n]*inv(f[m])%MOD*inv(f[n-m])%MOD;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();
    int q; cin>>q;

    for(int i=0 ; i<q ; i++){
        ll n,m; cin>>n>>m;
        cout<<c(n,m)<<'\n';
    }

    return 0;
}