#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    int ans = 1;
    int l = 0;
    for(int i=1 ; i<n ; i++){
        if(a[i]<=a[i-1]+1 && a[i]>a[l]) continue;

        l = i;
        ans++;
    }

    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    ll T; cin>>T;
    while(T--) solve();

    return 0;
}
