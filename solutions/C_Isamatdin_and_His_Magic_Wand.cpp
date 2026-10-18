#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    bool odd = false;
    bool even = false;

    for(ll &x : a){
        if(x%2) odd = true;
        else even = true;
    }

    if(!even || !odd){
        for(int i=0 ; i<n ; i++) cout<<a[i]<<" ";
    }else{
        sort(a.begin(),a.end());
        for(int i=0 ; i<n ; i++) cout<<a[i]<<" ";
    }
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}