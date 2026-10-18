#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

void solve(){
    int n,w; cin>>n>>w;
    vector<ll> c(n+1);
    for(int i=1 ; i<=n ; i++) cin>>c[i];

    vector<ll> cost(2*w);
    for(int i=1 ; i<=n ; i++) cost[i%(2*w)]+=c[i];

    ll sum=0;
    for(int i=0 ; i<w ; i++) sum+=cost[i];

    ll ans=sum;

    for(int i=0 ; i<2*w ; i++){
        sum-=cost[i];
        sum+=cost[(i+w)%(2*w)];
        ans=min(ans,sum);
    }
        ans=min(ans,sum);

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}