#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    ll mm = n%11;

    if(n>=111*mm){
        cout<<"YES\n";
    }else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}