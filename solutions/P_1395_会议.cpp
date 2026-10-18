#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 5e4+9;
vector<int> g[N];

ll n; 
ll siz[N];
ll f[N];
ll ans=0;
ll dep[N];
int center=0;

void getcenter(int cur, int fa)
{
    siz[cur]=1;
    for(int& v : g[cur]){
        if(v==fa) continue;

        getcenter(v,cur);
        siz[cur]+=siz[v];
        f[cur]=max(f[cur],siz[v]);
    }
    f[cur]=max(f[cur],n-siz[cur]);
    if(f[cur]<f[center] || (f[cur]==f[center] && cur<center) ) center=cur;
}

void dfs(int cur, int fa)
{
    for(int &v : g[cur]){
        if(v==fa) continue;

        dep[v]=dep[cur]+1;
        ans+=dep[v];
        dfs(v,cur);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    f[center]=n;
    getcenter(1,0);
    dep[center]=0;
    dfs(center,0);

    cout<<center<<' '<<ans;
}