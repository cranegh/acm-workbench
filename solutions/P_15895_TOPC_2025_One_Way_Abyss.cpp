#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,m; cin>>n>>m;
    vector<ll> p(n+1,0);
    for(int i=0 ; i<m ; i++){
        int x,y; ll v;
        cin>>x>>y>>v;

        ll oldpx=p[x];
        ll oldpy=p[y];

        p[x]=oldpy+v;
        p[y]=oldpx+v;
    }

    ll mx=0;
    for(int i=1 ; i<=n ; i++){
        if(mx<p[i]) mx=p[i];
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