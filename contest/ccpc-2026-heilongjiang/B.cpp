#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll l,r; cin>>l>>r;
    ll rr = min(l+10,r);

    int mx = -1;

    for(ll i=l ; i<=rr ; i++){
        ll tt = i;
        while(tt>0){
            if((tt%10)>mx) mx = tt%10;
            tt/=10;
        }
    }

    cout<<mx<<" ";
    
    ll tt1 = l; int cnt1=0; while(tt1>=10){tt1/=10, cnt1++;}
    ll tt2 = r; int cnt2=0; while(tt2>=10){tt2/=10, cnt2++;}

    ll ans = 0;
    for(ll i=l ; i<=rr ; i++){
        ll tt = i;
        bool pp = false;
        while(tt>0){
            if((tt%10)==mx){pp = true; ans=i ; break;}
            tt/=10;
        }
        if(pp) break;
    }

    if(cnt2>cnt1) for(int j=1 ; j<=cnt2 ; j++){
        ll cur = 1;
        for(int i=1 ; i<j ; i++) cur*=10; cur*=10; cur+=mx;
        if(l<=cur && cur<=r) ans=cur;
    }

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}