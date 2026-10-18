#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 65;
ll w[N],v[N],sum_w[N],sum_v[N];

ll dfs(int i, ll c)
{
    if(i==0) return 0;

    if(c>=sum_w[i]) return sum_v[i];

    if(c>=w[i]){
        return max(dfs(i-1,c-w[i])+v[i] , sum_v[i-1]);
    }

    return dfs(i-1,c);

}

void solve()
{
    int n; cin>>n;
    ll W; cin>>W;

    for(int i=1 ; i<=n ; i++) cin>>w[i]>>v[i];

    for(int i=1 ; i<=n ; i++) sum_w[i] = sum_w[i-1] + w[i]; 
    for(int i=1 ; i<=n ; i++) sum_v[i] = sum_v[i-1] + v[i]; 

    cout<<dfs(n,W)<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}