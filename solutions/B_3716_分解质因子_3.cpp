#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    int ans=0;

    for(ll i=2 ; n/i>=i ; i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            if(cnt%2==1) ans^=i;
        }
    }

    if(n>1) ans^=n;

    cout<<ans;
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}