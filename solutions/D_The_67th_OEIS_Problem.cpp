#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    ll i=1;

    for(int k=0 ; k<n ; i+=2,k++){
        cout<<i*(i+2)<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}