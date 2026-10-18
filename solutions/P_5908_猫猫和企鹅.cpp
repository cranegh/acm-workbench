#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 1e5+9;
vector<int> g[N];

ll dist[N];
ll d;
ll cnt=0;

void dfs(int u, int f)
{
    if(u!=1) dist[u]=dist[f]+1;
    if(dist[u]<=d) cnt++;
    else if(dist[u]>d) return;

    for(int &v : g[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n>>d;
    for(int i=1 ; i<n ; i++){
        int p,q;
        cin>>p>>q;
        g[p].push_back(q);
        g[q].push_back(p);
    }

    dfs(1,0);
    ll ans=cnt-1;

    cout<<ans;

    return 0;
}