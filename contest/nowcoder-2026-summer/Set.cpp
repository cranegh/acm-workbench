#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    int cnt_odd = 0;
    ll mx = 0;

    for(int i=0 ; i<n ; i++){
        ll x; cin>>x;
        if(x%2) cnt_odd++;
        if(x>mx) mx = x;
    }

    int ans = 0;
    if(cnt_odd%2){//odd
        if(mx%2) ans = (mx+1)>>1;
        else ans = mx/2;
    }else{//even
        if(mx%2) ans = (mx-1)>>1;
        else ans = mx/2;
    }

    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}