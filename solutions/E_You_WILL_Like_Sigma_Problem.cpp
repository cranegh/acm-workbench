#include<bits/stdc++.h>

using namespace std;
using ll = long long;

using ll = long long;

const int N = 5e5+9;
const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    vector<ll> a(n+1); for(int i=1 ; i<=n ; i++) cin>>a[i];
    vector<ll> b(m+1); for(int i=1 ; i<=m ; i++) cin>>b[i];

    ll sumb=0;
    for(int i=1 ; i<=m ; i++) sumb=(sumb+b[i]);

    vector<ll> prea(n+1);
    for(int i=1 ; i<=n ; i++) prea[i]=(prea[i-1]+a[i]);

    ll s1=0;
    for(int i=1 ; i<=n ; i++) s1=(s1+i*a[i]%MOD%MOD*(sumb%MOD))%MOD;

    ll s2=0;
    for(int j=1 ; j<=m ; j++){
        int k=1;
        for(k=1 ; (k+1)*j<=n ; k++){  
            s2=(s2+k*j%MOD*(b[j]%MOD)%MOD*((prea[(k+1)*j-1]-prea[k*j-1])%MOD))%MOD;
        }
        if(k*j-1<=n) s2=(s2+k*j%MOD*(b[j]%MOD)%MOD*((prea[n]-prea[k*j-1])%MOD))%MOD;
    }

    ll ans = (s1-s2)%MOD;

    cout<<(ans+MOD)%MOD;
    
    return 0;
}