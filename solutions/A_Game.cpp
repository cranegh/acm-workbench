#include <iostream>

using namespace std;

void solve()
{
    int k; cin>>k;
    int a1,b1; cin>>a1>>b1;
    int a2,b2; cin>>a2>>b2;

    if(a1+a2+0<b1+b2+k) cout<<"YES\n";
    else if(a1+a2+0==b1+b2+k){
        if(a1>b1 && a2>b2) cout<<"NO\n";
        else cout<<"YES\n";
    }else cout<<"NO\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}