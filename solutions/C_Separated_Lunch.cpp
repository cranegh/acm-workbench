#include<bits/stdc++.h>

using namespace std;
using ll = long long;

using ll = long long;

const int N = 25;
const int MOD = 998244353;

ll ans=2e9+9;
ll sum=0;
int n;
ll k[N];

void dfs(int i, ll cur_sum)
{
    ll cur_mx=max(cur_sum,sum-cur_sum);
    ans=min(ans,cur_mx);
    if(cur_sum==cur_mx){
        if(cur_sum>ans) return;
    }

    if(i==n) return;

    dfs(i+1,cur_sum+k[i]);
    dfs(i+1,cur_sum);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    for(int i=0 ; i<n ; i++) cin>>k[i];
    for(int i=0 ; i<n ; i++) sum+=k[i];

    dfs(0,0);

    cout<<ans;
    
    return 0;
}