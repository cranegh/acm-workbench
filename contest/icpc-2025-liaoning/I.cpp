#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;

    vector<ll> v(n-1);
    ll x; cin>>x;
    for(int i=0; i<n-1; i++) cin>>v[i];
    sort(v.begin(),v.end());

    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}