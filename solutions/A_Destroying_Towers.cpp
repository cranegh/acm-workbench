#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> h(n);
    for(int i=0 ; i<n ; i++) cin>>h[i];

    int mn = 1000;
    int ans = 0;

    for(int i=0 ; i<n ; i++){
        if(h[i]<mn) mn = h[i];
        ans += mn;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}