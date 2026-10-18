#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int a,b; cin>>a>>b;
    a%=2; b%=2;
    bool pp=true;
    if(a+b>1) pp = false;

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}