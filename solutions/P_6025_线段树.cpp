#include<iostream>

using namespace std;
using ll = long long;

const int N =5e5+9;

ll ans=0;

int build(ll l, ll r, ll i){
    if(l==r){
        ans^=i;
        return i;
    }
    
    ll mid = (l+r)>>1;
    ll res = max(build(l,mid,i<<1),build(mid+1,r,i<<1|1));

    ans^res;
    return res;
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int l,r; cin>>l>>r;
    build(l,r,1);

    cout<<ans;
    
    return 0;
}