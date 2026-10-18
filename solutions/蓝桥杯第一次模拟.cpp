#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

ll f(ll x){
    if(x==1) return 1;
    else return x*f(x-1); 
}

ll qpow(ll a , int n)
{
    ll res=1;
    while(n>0){
        if(n%2==1) res*=a;
        n/=2;
        a*=a;
    }
    return res;
}

ll inv(ll x){
    return 
}

ll c(ll n, ll m){
    return f(m)
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    ll x; cin>>x;
    cout<<f(x);

    return 0;
}