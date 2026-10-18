#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,tt; cin>>n>>tt;
    vector<ll> t(n);
    vector<ll> k(n);
    for(int i=0 ; i<n ; i++) cin>>t[i]>>k[i];

    ll x = 0;
    for(int i=0 ; i<n ; i++){
        x = max(x+1,min(x+t[i],k[i]+tt+1));
    }

    cout<<x;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}