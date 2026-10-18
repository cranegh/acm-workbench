#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a,b,x,y; cin>>a>>b>>x>>y;
    if(x < 0) x = -x;
    if(y < 0) y = -y;

    ll d = min(x,y);

    ll mn = min(a,b);
    ll ans = 2*d*mn;
    if(x > d){
        ll dd = (x-d+1)/2;
    
        if(a > 3*b){
            ans += dd*3*b;
            ans += (x-d-dd)*b;
        }
        else if(b > 3*a){
            ans += dd*a;
            ans += (x-d-dd)*3*a;
        }
        else{
            ans += dd*a;
            ans += (x-d-dd)*b;
        }
    }else{
        ll dd = (y-d+1)/2;

        if(a > 3*b){
            ans += dd*b;
            ans += (y-d-dd)*3*b;
        }
        else if(b > 3*a){
            ans += dd*3*a;
            ans += (y-d-dd)*a;
        }
        else{
            ans += dd*b;
            ans += (y-d-dd)*a;
        }

    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}