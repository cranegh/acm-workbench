#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    bool pp = true;
    for(int i=0 ; i<n ; i++){
        ll cur = a[i] - (i+1);
        if(cur<0) pp = false;
        if(!pp) break;
        a[i] = i+1;
        if(i<n-1) a[i+1] += cur;
    }

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}