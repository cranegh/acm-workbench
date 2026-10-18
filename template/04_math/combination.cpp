// 组合数
// 阶乘与快速幂逆元求组合数；预处理 O(n)，查询 O(log MOD)
// 先 init(最大 n)，0<=n<N 且 n<MOD；保留原 inv 快速幂和单次求逆
#include<bits/stdc++.h>

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

void init(int n){
    f[0]=1;
    for(int i=1 ; i<=n ; i++) f[i]=i*f[i-1]%MOD;
}

ll c(ll n , ll m){
    if(m<0 || m>n) return 0;
    return f[n]*inv(f[m])%MOD*inv(f[n-m])%MOD;
}

