#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,m,rs,cs,ru,cu;
    cin>>n>>m>>rs>>cs>>ru>>cu;

    ll ans = 0;
    if(rs < ru){
        ans = max(ans,ru-1);
    }else if(rs > ru){
        ans = max(ans,n-ru);
    }
    
    if(cs < cu){
        ans = max(ans,cu-1);
    }else if(cs > cu){
        ans = max(ans,m-cu);
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