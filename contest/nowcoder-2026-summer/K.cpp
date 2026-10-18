#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    unordered_map<ll,bool> mp;
    for(int i=-k ; i<=k ; i++) mp[a[(i+n)%n]] = true;
    ll cur = 0;
    while(mp.count(cur)!=0 && mp[cur]) cur++;

    vector<ll> b(n); 
    b[0] = cur;
    int l = -k;
    int r = k;

    for(int i=1 ; i<n ; i++){
        l++,r++;
        mp[a[(l+1+n)%n]] = false;
        mp[(r+1+n)%n] = true;
        if(a[(l+1+n)%n]<cur) cur = a[(l+1+n)%n];
        b[i] = cur;
    }

    for(int i=0 ; i<n ; i++) cout<<b[i]<<" ";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}