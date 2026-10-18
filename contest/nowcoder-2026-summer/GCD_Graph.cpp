#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e7+5;

vector<ll> getprime(ll n)
{
    vector<ll> p;
    for(ll i=2 ; i*i<=n ; i++){
        if(n%i) continue;
        p.push_back(i);
        while(n%i==0) n/=i;
    }
    if(n>1) p.push_back(n);
    return p;
}

ll inclusionExclusion(ll x,const vector<ll>& a)
{
    int n = a.size();
    ll ans = 0;

    for(int mask=1 ; mask<(1<<n) ; mask++){
        ll common = 1;
        int cnt = 0;

        for(int i=0 ; i<n ; i++){
            if(!(mask>>i&1)) continue;
            cnt++;

            ll g = gcd(common,a[i]);
            ll mul = a[i]/g;

            // lcm(common,a[i])>x，此时交集大小为 0
            if(common>x/mul){
                common = x+1;
                break;
            }
            common*=mul;
        }

        if(common>x) continue;
        if(cnt&1) ans+=x/common;
        else ans-=x/common;
    }
    return ans;
}

void solve()
{
    ll l,r,n; cin>>l>>r>>n;
    vector<ll> v = getprime(n);

    ll cntr = inclusionExclusion(n,v);




}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}