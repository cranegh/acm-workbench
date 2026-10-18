#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll R[N],C[N];

ll n,m;
ll cal(ll d, ll m){
    ll res = 0;
    for(int i=1; i<=m; i++){
        res += R[i]*((C[i]+d)/(d+1));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,m; cin>>n>>m;
    
    ll l=0,r=0;
    for(int i=1; i<=m; i++){
        cin>>R[i]>>C[i];
        r = max(r,C[i]);
    }

    while(l+1!=r){
        ll mid = (l+r)>>1;
        
        ll cur = cal(mid,m);
        if(cur < n) r = mid;
        else l = mid;
    }

    cout<<l;
    
    return 0;
}