#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;
    vector<ll> a;
    vector<ll> l(n+1);
    for(ll i=1 ; i<=n ; i++){
        ll lx; cin>>lx;
        l[i]=lx;
        for(ll j=0 ; j<lx ; j++){
            ll x; cin>>x;
            a.push_back(x);
        }
    }

    vector<ll> c(n+1);
    for(ll i=1 ; i<=n ; i++) cin>>c[i];

    ll idx=1;
    ll ai=1;
    ll i=1;
    for(i=1 ; i<=n ; i++){
        ll curl=idx;
        ll curr=idx+c[i]*l[i]-1;
        
        if(curl<=k && k<=curr){
            ll curi=k-curl;
            curi%=l[i];
            
            ll ansi=ai+curi-1;
            cout<<a[ansi];
            break;
        }
        idx=curr+1;
        ai+=l[i];
    }
    
    return 0;
}

