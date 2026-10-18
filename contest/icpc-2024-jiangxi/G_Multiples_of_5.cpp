#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int m; cin>>m;
    ll mm=0;
    for(int i=0 ; i<m ; i++){
        ll u; char v1;
        cin>>u>>v1;
        int v;
        if('0'<=v1 && v1<='9') v=v1-'0';
        else if(v1=='A') v=10;

        ll cur=u*1ll*v;

        mm+=cur;
        mm%=5;
    }

    if(mm%5==0) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}