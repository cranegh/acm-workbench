#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct ele{
    ll a1,a2;
};

void solve()
{
    int n; ll m;
    cin>>n>>m;
    vector<ele> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i].a1>>v[i].a2;
    
    ll ans1 = 0;
    ll tar1 = v[0].a1+m;
    if(v[0].a2 > tar1) ans1++;
    for(int i=1 ; i<n ; i++){
        ll x = min(v[i].a1,v[i].a2);
        ll y = max(v[i].a1,v[i].a2);

        ll need = max(tar1-x,0ll)+max(tar1-y,0ll);
        if(x>tar1) ans1+=2;
        else if(y>tar1) ans1++;
        else if(m>need) ans1++;

    }

    ll ans2 = 0;
    ll tar2 = v[0].a1;
    if(v[0].a2+m > tar2) ans2++;
    for(int i=1 ; i<n ; i++){
        ll x = min(v[i].a1,v[i].a2);
        ll y = max(v[i].a1,v[i].a2);

        ll need2 = max(tar2-x,0ll)+max(tar2-y,0ll);
        ll need1 = max(tar2-y,0ll);
        if(m>need2) ans2+=2;
        else if(m>need1) ans2++;
    }
    cout<<ans1<<" "<<ans2<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}