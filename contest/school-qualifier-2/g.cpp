#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll l,r; cin>>l>>r;

    if(r>l){
        cout<<1<<'\n';
        cout<<1<<'\n';
    }else{
        vector<ll> ans;
        for(ll i=1 ; i*i<=l ; i++){
            if(l%i==0){
                ans.push_back(i);
                if(i*i!=l) ans.push_back(l/i);
            }
        }

        sort(ans.begin(),ans.end());

        cout<<ans.size()<<'\n';
        for(ll &x : ans) cout<<x<<" ";
    }

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}