#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,k; 

bool check(ll mid, vector<ll>& a)
{
    ll res=0;
    for(ll i=0 ; i<n ; i++){
        ll aa = mid - a[i];
        if(aa<0) continue;
        ll bb = i+1;

        ll cur = ((aa+bb-1)/bb);
        res+=cur;
        if(res>k) return false;
    }

    if(res<=k){
        //cout<<res<<" ";
        return true;
    }
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k;
    vector<ll> a(n);
    for(ll i=0 ; i<n ; i++) cin>>a[i];

    ll l=0,r=3e18;
    while(l+1!=r){
        ll mid=(l+r)>>1;

        if(check(mid,a)) l=mid;
        else r=mid;
    }

    cout<<l;
    //cout<<" ";
    //cout<<r;
    
    return 0;
}

