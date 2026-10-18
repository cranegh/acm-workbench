#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,k; cin>>n>>k;
    ll ou=0,ji=0;

    if(k%2==0){
        ou = k;
        ji = k-1;
    }else{
        ji = k;
        ou = k-1;
    }

    ll ans = 0;
    if(n%2==0){
        ans += n/ou;
        if(n%ou) ans++;
    }else{
        n -= ji;
        ans++;

        ans += n/ou;
        if(n%ou) ans++;
    }

    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}