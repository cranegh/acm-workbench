#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll m; cin>>m;
    ll ans=1;
    for(int i=1 ; i<m ; i++){
        ans=(ans*2)%MOD;
    }
    ans%=MOD;

    cout<<ans;

    return 0;
}