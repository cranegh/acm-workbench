#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 1e3+9;
int a[N],sum[N];

int n,c;
bool vis[N];
int ans=0;

void dfs(int dep , int cnt){
    ans=max(ans,cnt);
    if(dep==0){
        return;
    }
    if(cnt+sum[dep]<=ans) return;

    if(cnt+a[dep]<=c) dfs(dep-1,cnt+a[dep]);

    dfs(dep-1,cnt);

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>c;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1; i<=n ; i++) sum[i]+=sum[i-1]+a[i];

    dfs(n,0);

    cout<<ans;

    return 0;

}