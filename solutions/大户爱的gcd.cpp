#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    while(b!=0)
    {
        ll temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}

void solve()
{
    ll n,m,q; cin>>n>>m>>q;
    vector<ll> a(n,1);
    for(int i=0 ; i<m ; i++){
        ll x,y,g; cin>>x>>y>>g;
        x--,y--;
        a[x]=lcm(a[x],g);
        a[y]=lcm(a[y],g);
    }
    for(int i=0 ; i<q ; i++){
        ll x,y; cin>>x>>y;
        x--; y--;
        cout<<gcd(a[x],a[y])<<'\n';
    }
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}