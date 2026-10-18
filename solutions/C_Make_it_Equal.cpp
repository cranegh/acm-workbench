#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n,k; cin>>n>>k;
    vector<ll> s(n); for(int i=0 ; i<n ; i++) cin>>s[i];
    vector<ll> t(n); for(int i=0 ; i<n ; i++) cin>>t[i];

    unordered_map<ll,int> mp;
    for(int i=0 ; i<n ; i++){
        ll cur = t[i]%k;
        mp[cur]++;
    }
    
    bool pp = true;
    for(int i=0 ; i<n ; i++){
        ll cur = s[i]%k;
        ll a = cur;
        ll b = k-cur;
        if(mp[a]>0){
            mp[a]--;
        }else if(mp[b]>0){
            mp[b]--;
        }else pp = false;
    }
    
    for(int i=0 ; i<n ; i++){
        ll cur = t[i]%k;
        if(mp[cur]>0) pp = false;
    }
    
    if(pp) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}