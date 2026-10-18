#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

ll getnum(vector<ll>& v, ll len)
{
    ll res=0;
    ll nn = v.size();
    for(ll i=0 ; i<nn ; i++){
        res+=v[i]/len;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,k; cin>>n>>k;
    vector<ll> v(n); for(ll i=0 ; i<n ; i++) cin>>v[i];

    ll mx=v[0];
    for(ll i=0 ; i<n ; i++)
        if(mx<v[i]) mx=v[i];

    ll l=0,r=mx;
    while(l+1!=r)
    {
        ll mid = (l+r)>>1;
        ll curk = getnum(v,mid);

        if(curk>=k) l=mid;
        else r=mid;
    }

    cout<<l;

    return 0;
}