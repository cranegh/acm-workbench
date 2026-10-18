#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> a(n+1);
    vector<ll> pre(n+1,0);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1 ; i<=n ; i++) pre[i] = pre[i-1] + a[i];

    if(k%2==1){
        int l = k/2;
        int r = k-l;

        ll curl = pre[l];
        ll mxdelta = -INF;
        for(int i=l+1 ; i<=n-r+1 ; i++){
            ll cur = a[i];
            ll curr = pre[i+r-1]-pre[i];
            //cout<<a[i]<<" "<<curr<<'\n';
            //cout<<cur<<" "<<curl<<" "<<curr<<'\n';
            ll curdelta = (cur*l-curl) - (curr-cur*l);
            //cout<<curdelta<<'\n';
            if(curdelta>mxdelta) mxdelta = curdelta;
        }
        //cout<<mxdelta<<'\n';
        ll ans = pre[n] + mxdelta;
        cout<<ans<<'\n';
    }else if(k%2==0){
        int l = k/2-1;
        int r = k-l;

        ll curl = pre[l];
        ll mxdelta = -INF;
        for(int i=l+1 ; i<=n-r+1 ; i++){
            ll curr = pre[i+r-1]-pre[i+1];
            //cout<<a[i]<<" "<<curr<<'\n';
            //cout<<cur<<" "<<curl<<" "<<curr<<'\n';
            ll curdelta = (a[i]+a[i+1])*l-curl-curr;
            //cout<<curdelta<<'\n';
            if(curdelta>mxdelta) mxdelta = curdelta;
        }
        //cout<<mxdelta<<'\n';
        ll ans = pre[n] + mxdelta;
        cout<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}