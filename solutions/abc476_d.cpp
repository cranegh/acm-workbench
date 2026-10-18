#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,m,k; cin>>n>>m>>k;
    ll x,y; cin>>x>>y;

    vector<ll> a(n); for(int i=0; i<n; i++) cin>>a[i];
    vector<ll> b(m); for(int i=0; i<m; i++) cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll sumk = k*y;
    ll kmx = 0;
    for(int i=0; i<m; i++){
        ll curused = (b[i]+k-1)/k;
        if(sumk < curused*k) break;
        
        sumk -= curused*k;
        kmx++;
    }

    vector<ll> prea(n+1,0);
    vector<ll> preb(m+1,0);

    for(int i=1; i<=n; i++){
        prea[i] = prea[i-1] + a[i-1];
    }

    for(int i=1; i<=m; i++){
        preb[i] = preb[i-1] + b[i-1];
    }

    ll ans = 0;
    for(int i=0; i<=kmx; i++){
        ll cur = i;

        ll cur_sum = x + k*y - preb[i];
        int l = 0, r = n+1;
        while(l+1!=r){
            int mid = (l+r)>>1;

            if(cur_sum >= prea[mid]) l = mid;
            else r = mid;
        }

        cur += l;
        ans = max(ans,cur);
    }
 
    cout<<ans;

    return 0;
}
