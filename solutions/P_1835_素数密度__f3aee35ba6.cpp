#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

bitset<50005> used;
bitset<N> vis;
vector<ll> primes;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll l,r; cin>>l>>r;
    
    int m = sqrt(r);

    used[1] = true;
    for(int i=2; i<=m; i++){
        if(!used[i]) for(int j=i*i; j<=50000; j+=i) used[j] = true;
    }
    
    for(int i=2; i<=50000; i++){
        if(!used[i]) primes.push_back(i);
    }
    
    
    if(l == 1) vis[0] = true;
    for(ll &p : primes){
        if(p*p > r) break;
        ll st = max((l+p-1)/p*p,p*p);
        
        for(ll i=st; i<=r; i+=p){
            vis[i-l] = true;
        }
    }

    int ans = 0;
    for(int i=0; i<=r-l; i++){

        if(!vis[i]) ans++;
    }

    cout<<ans;

}