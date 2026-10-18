#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

void solve()
{
    string ss; cin>>ss;
    ll x=0;
    for(int i=0 ; i<ss.length() ; i++)
        if(ss[i]!='.') x = x*10 + (ss[i]-'0');

    ll p = 4*x-300;
    
    ll a = p/100;
    ll b = p%100;

    //cout<<p<<'\n';

    if(b>=10) cout<<a<<"."<<b<<'\n';
    else cout<<a<<".0"<<b<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}