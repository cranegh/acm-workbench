#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    ll mx = 0, mn = 0;
    for(int i=0 ; i<n ; i++){
        ll lmx = mx;
        ll lmn = mn;

        mx = max(lmx-a[i],b[i]-lmn);
        mn = min(b[i]-lmx,lmn-a[i]);
    }

    cout<<mx<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}