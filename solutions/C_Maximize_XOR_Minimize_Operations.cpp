#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll x,y; cin>>x>>y;
    ll S = x+y;

    int nx = 0;
    bool Smaller = false;
    for(int i=30; i>=0; i--){
        int xb = (x>>i)&1;
        int sb = (S>>i)&1;

        if(Smaller){
            if(sb) nx |= (1ll<<i);
        }
        else{
            if(xb==1){
                if(sb) nx |= (1ll<<i);
                else{
                    Smaller = true;
                }
            }
        }
    }
    cout<<S<<" "<<x-nx<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}