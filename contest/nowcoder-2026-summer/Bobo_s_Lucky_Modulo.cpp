#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n; cin>>n;
    ll ans = 0;
    for(ll b=1 ; b*b<=n ; b++){
        ll k = (n+1)/(b*(b+1));
        ans += k*b;

        k++;
        ll last_left = k*b*(b+1)-b;
        if(last_left <= n) ans += (n-last_left+1);
    }
    
    cout<<ans;

    return 0;
}