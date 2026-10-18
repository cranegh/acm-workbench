#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a,b,x; cin>>a>>b>>x;
    
    int ans = 10000;
    ll cura = a;

    for(int i=0 ; i<65 ; i++){
        if(i>0) cura/=x;

        ll curb = b;
        for(int j=0 ; j<65 ; j++){
            int cnt = i+j;

            if(j>0) curb/=x;

            cnt += abs(cura-curb);
            ans = min(ans,cnt);
        }
    }

    cout<<ans<<'\n';

    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}