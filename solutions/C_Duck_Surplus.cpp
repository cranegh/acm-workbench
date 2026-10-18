#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    for(int i=0 ; i<n-1 ; i++){
        if(a[i+1]<a[i]){
            ll t = a[i+1];
            a[i+1] += a[i];
            a[i] = t;
        }
    }

    cout<<a[n-1]<<'\n';


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}