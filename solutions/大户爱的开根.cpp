#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,k; 

ll qpow(ll m, ll cn)
{
    ll res=1;
    while(cn>0){
        if(cn%2==1){
            //cout<<res<<'\n';
            res*=m;
            if(res>n) return n+2;
        }
        m*=m;
        //cout<<m<<'\n';
        cn/=2;
        if(m>n && cn>0) return n+2;
    }
    return res;
}

void solve()
{
    cin>>n>>k;
    ll l=0,r=n;
    while(l+1!=r)
    {
        ll mid = (l+r)>>1;
        ll nn = qpow(mid,k);
        //cout<<l<<" "<<r<<" "<<mid<<" "<<nn<<"\n";
        if(nn>n) r=mid;
        else l=mid;
    }
    cout<<l<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}