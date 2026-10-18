#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    vector<ll> ans;

    for(ll i=2 ; n/i>=i ; i++){
        if(n%i==0){
            while(n%i==0){
                ans.push_back(i);
                n/=i;
            }
        }
    }

    if(n>1) ans.push_back(n);

    sort(ans.begin(),ans.end());

    for(auto &x : ans) cout<<x<<' ';
    cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}