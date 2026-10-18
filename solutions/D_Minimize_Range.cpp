#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 2e5+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,k; cin>>n>>k;
    vector<ll> v(n);

    for(int i=0 ; i<n ; i++) cin>>v[i];
    for(int i=0 ; i<n ; i++) v[i]%=k;

    sort(v.begin(),v.end());

    ll ans=v[n-1]-v[0];
    for(int i=0 ; i<n-1 ; i++){
        ll cur = v[i]+k-v[i+1];
        ans=min(ans,cur);
    }

    cout<<ans;

    return 0;
}