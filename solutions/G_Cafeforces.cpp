#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; ll s; cin>>n>>s;
    vector<ll> p(n); for(int i=0 ; i<n ; i++) cin>>p[i];
    
    for(int i=0 ; i<n ; i++){
        if((s+p[i]+1)/2 > s) s = (s+p[i]+1)/2;
    }

    cout<<s<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}