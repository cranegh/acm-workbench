#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);

    for(int i=0 ; i<n ; i++){
        cin>>a[i]>>b[i];
    }

    for(int i=0 ; i<n ; i++) c[i] = b[i]-a[i];

    ll ans = 0;

    for(int i=0 ; i<n ; i++) ans += a[i];

    



    
    
    return 0;
}