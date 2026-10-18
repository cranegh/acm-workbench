#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 100005;
ll f[N];

void init()
{
    f[1] = 1;
    for(ll i=2 ; i<=100000 ; i++) f[i] = (f[i-1]*i)%MOD;
}

void solve()
{
    int n; cin>>n;
    vector<int> degree(n+1,0);

    int mx = 0;
    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        degree[u]++;
        degree[v]++;
    }

    ll ans = 1;
    for(int i=1 ; i<=n ; i++){
        ll d = degree[i];
        if(d==1) continue;

        if(d%2){
            ans = (ans*d)%MOD;
            d--;
        }
        for(int j=d-1 ; j>=1 ; j-=2){
            ans = (ans*j)%MOD;
        }
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    void init();

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}