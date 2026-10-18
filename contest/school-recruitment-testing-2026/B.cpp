#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k,p; cin>>k>>p;

    ll ans = p*(1<<k);

    cout<<ans;

}