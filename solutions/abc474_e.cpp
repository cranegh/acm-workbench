#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n+1);
    vector<ll> b(n+1);
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
    
    ll sum = 0;
    ll A = INF;
    for(int i=1; i<=n; i++) sum += a[i];
    for(int i=1; i<=n; i++) A = min(A,a[i]);
    vector<ll> d(n,0);
    for(int i=1; i<=n; i++) d[i-1] = a[i] - b[i];
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());

    vector<ll> pre(n+1,0);
    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + d[i-1];

    ll ans = INF;
    for(int k=0; k<=n; k++){
        ll extra = max(2ll*k-n,0ll)*A;
        ll cur = sum-pre[k]+extra;
        if(cur<ans) ans = cur;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}