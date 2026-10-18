#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n ; i++) cin>>b[i];

    ll mx=0,mn=0;
    for(int i=0 ; i<n ; i++){
        ll v1=mn-a[i];
        ll v2=mx-a[i];
        ll v3=b[i]-mn;
        ll v4=b[i]-mx;

        mn=min({v1,v2,v3,v4});
        mx=max({v1,v2,v3,v4});
    }

    cout<<mx<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}