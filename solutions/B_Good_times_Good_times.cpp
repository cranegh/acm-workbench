#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll x; cin>>x;
    ll yy = 1;
    ll xx = x;
    int cnt = 0;
    while(xx){
        xx/=10;
        yy*=10;
    }
    yy += 1;

    cout<<yy<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}