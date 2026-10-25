#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll a,b,ca,cb,fa;
    cin>>a>>b>>ca>>cb>>fa;

    ll ans = 0;

    ll need = fa - a - (b/cb)*ca;
    b = b%cb;
    if(need <= 0){
        need = 0;
        cout<<0<<'\n';
        return;
    }
    
    ll ans1 = need-b+cb-1;
    ll k = (need-1)/ca;
    ll ans2 = ans1 - k*(ca-cb);

    ans = max(ans1,ans2);

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T;
    while(T--) solve();

}