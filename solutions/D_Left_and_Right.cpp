#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll l,r; cin>>l>>r;
    ll ans = l-1;

    if(l==r){
        if(l!=1) cout<<"infty\n";
        else cout<<0<<'\n';
        return;
    }

    ll k = r-l;
    ll n = (l-1)/k;

    ans += (l-k-1)*n-n*(n-1)*k/2;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}