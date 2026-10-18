#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,m; cin>>n>>m;
    
    ll ans = 0;
    if(n%2==1 || m%2==1){
        ans = (n*m+1)/2;
    }else{
        ans = m*n/2-min(m,n);
    }

    cout<<ans<<'\n';

}



int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}