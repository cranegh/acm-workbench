#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a,b; cin>>a>>b;
    ll i = b-a+1;

    ll ans = 0;
    if(a%2==0){
        i%=4;
        for(int j=0 ; j<i ; j++) ans^=(b-j);
        cout<<ans<<'\n';
    }else if(a%2==1){
        i%=4;
        if(i==0) i+=4;
        ans = a;
        if(i==2) ans^=b;
        else if(i==3) ans^=(b-1)^b;
        else if(i==4) ans^=(b-2)^(b-1)^b;

        cout<<ans<<'\n';
    }
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}