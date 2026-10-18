#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> p(n);
    for(int i=0 ; i<n ; i++) cin>>p[i];

    ll ans = 0;
    for(int i=0 ; i<n ; i++){
        ans += p[i]*(2*i-n+1);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}