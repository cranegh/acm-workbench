#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    vector<ll> b(n); for(int i=0 ; i<n ; i++) cin>>b[i];

    vector<ll> aa(n);
    for(int i=0 ; i<n ; i++) aa[i] = b[i] - a[i];

    bool pp = true;
    for(int i=n-1 ; i>=0 ; i--){
        if(i==0 && aa[i]<0){
            pp = false; 
            break;
        }
        if(aa[i]<0){
            aa[i-1] -= (-aa[i]);
        }
    }

    if(!pp) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}