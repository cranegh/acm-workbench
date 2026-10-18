#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<bitset>
#include<stack>

using namespace std;
using ll = long long;

const int N = 1e4+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> v(n+1);
    vector<ll> pre(n+1,0);

    for(int i=1 ; i<=n ; i++) cin>>v[i];
    for(int i=1 ; i<=n ; i++) pre[i]+=pre[i-1]+v[i];

    ll ans=0;
    for(int i=1 ; i<=n ; i++){
        ll cur=pre[n]-pre[i];
        ans+=v[i]*cur;
    }

    cout<<ans;

    return 0;
}