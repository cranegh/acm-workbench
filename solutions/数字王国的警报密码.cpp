#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200000+5;
bitset<N> used;

void solve()
{
    used.reset(); used[0] = true;

    ll n,k; cin>>n>>k;
    if(n>=k){
        cout<<-1<<'\n';
        return;
    }
    
    vector<ll> ans(n);
    ll cur = 1;
    ll pre = 0;
    for(int i=0 ; i<n ; i++){
        while(used[(pre+cur)%k]) cur++;
        used[(pre+cur)%k] = true;
        pre += cur;
        ans[i] = cur;
        cur++;
    }
    for(ll &x : ans) cout<<x<<" ";
    cout<<'\n';
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}