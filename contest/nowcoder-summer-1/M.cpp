#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void solve()
{
    int n,m; cin>>n>>m;

    vector<ll> l(n, 1);
    for(int k=0 ; k<m ; k++){
        vector<ll> nl(n, 0);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                ll x; cin>>x;
                nl[j] = (nl[j] + l[i]*x) % MOD;
            }
        }
        l = nl;
    }

    vector<ll> r(n, 1);
    vector<ll> nr(n, 0);
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            ll x; cin>>x;
            nr[j] = (nr[j] + r[i]*x) % MOD;
        }
    }
    r = nr;

    if(l == r) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}
