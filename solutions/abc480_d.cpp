#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N];
ll pre[N], PRE[N];
int n,q; 

ll f(ll x){
    ll res = (1+x)*x/2;
    return res;
}
ll cnt[N];

ll getc(ll x){
    int l=0, r=n;
    while(l+1!=r){
        int mid = (l+r)/2;
        if(cnt[mid] < x) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + a[i];
    for(int i=1; i<=n; i++) PRE[i] = PRE[i-1] + pre[i];
    for(int i=1; i<=n; i++) cnt[i] = f(i);

    for(int i=0; i<q; i++){
        ll l,r; cin>>l>>r;

        ll cl = getc(l);
        ll cr = getc(r);
        ll rl = l - cnt[cl];
        ll rr = r - cnt[cr];

        ll res = PRE[cr] - PRE[cl+1];
        res += pre[rr];
        res += pre[cl+1] - pre[rl-1];
        cout<<res<<'\n';
    }

    return 0;
}