#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());

    ll t=0;
    for(int i=0 ; i<n ; i++)
    {
        if(v[i].first<=t) t+=v[i].second;
        else t=v[i].first+v[i].second;
    }

    cout<<t<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}