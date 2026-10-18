#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
using ll = long long;

ll n,m;

ll cal(int mid, vector<ll>& a, vector<ll>& b){
    ll sum=0;
    for(int i=0 ; i<mid ; i++) sum+=a[i]*b[i];
    sum+=a[mid]*b[mid];
    for(int i=mid ; i<n ; i++) sum+=a[i]*b[i+1];

    return sum;
}

void solve()
{
    cin>>n>>m;
    vector<ll> a(n);
    vector<ll> b(n+1);

    for(int i=0 ; i<n ; i++) cin>>a[i];
    for(int i=0 ; i<n+1 ; i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int l=0,r=n;
    ll cur_sum=0;

    while(l+1!=r){
        int mid=(l+r)/2;
        ll cur_sum=cal(mid,a,b);
        if(cur_sum>m) r=mid;
        else l=mid;
    }

    if(l==0 && cal(l,a,b)-a[0]*b[0]>=m){
        cout<<0<<'\n';
        return;
    }

    ll m_money=m-cal(l,a,b);
    if(m_money<0){
        m_money+=a[0]*b[0];
        cout<<(m_money+b[0]-1)/b[0]<<'\n';
        return;
    }

    ll ans = ((m_money+a[l]*b[l+1])+b[l+1]-1)/b[l+1];
    
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}