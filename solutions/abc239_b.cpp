#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x; cin>>x;
    if(x >= 0) cout<<x/10;
    else{
        ll ans = x/10;
        if(x%10) ans -= 1;
        cout<<ans;
    }

    return 0;
}