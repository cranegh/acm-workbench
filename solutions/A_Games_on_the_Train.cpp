#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    int mx = 0;
    int mn = 7;
    for(int i=0 ; i<n ; i++){
        int tt; cin>>tt;
        if(tt>mx) mx = tt;
        if(tt<mn) mn = tt;
    }

    int ans = mx-mn+1;
    cout<<ans<<'\n';

    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}