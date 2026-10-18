#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    ll mxa = *max_element(a.begin(),a.end());
    ll mxb = *max_element(b.begin(),b.end());

    ll ans = mxa+mxb;
    cout<<ans;

    return 0;
}