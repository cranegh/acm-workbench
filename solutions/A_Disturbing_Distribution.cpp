#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll ans=0;
    for(int i=0 ; i<n ; i++){
        if(i<n-1 && a[i]==1) continue;
        ans+=a[i];
    }

    cout<<ans;
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}