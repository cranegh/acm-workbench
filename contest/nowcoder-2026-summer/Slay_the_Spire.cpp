#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll x,a,b; cin>>x>>a>>b;

    ll ans = x;

    for(ll q=0 ; q*q<=2*x ; q++){
        ll part1 = (a-1)*q*q+(a+1)*q; part1/=2;
        ll l = -1;
        ll r = (x+b-1)/b;
        while(l+1!=r){
            ll t = (l+r)>>1;
            ll part2 = b*t;

            ll u = min((a-1)*q,t);
            ll part3 = -(u*u)+(2*(a-1)*q+1)*u; part3/=2;

            ll res = part1 + part2 + part3;
            if(res>=x) r = t;
            else l = t;
        }
        ll cur_ans = r+q;
        if(cur_ans<ans) ans = cur_ans;
    }

    cout<<ans;

    return 0;
}