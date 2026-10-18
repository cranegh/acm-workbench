#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

const int N = 2e5+9;

int n;
int far=0;
ll dist[N];
int f[N];

struct edge{
    int to;
    ll w;
};

vector<edge> g[N];
vector<int> B;
map< pair<int,int> , int > cnt;

void dfs(int u, int fa)
{
    f[u]=fa;
    for(auto& [v,w] : g[u])
    {
        if(v==fa) continue;
        
        dist[v]=dist[u]+w;
        if(dist[v]>dist[far]) far=v;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<n ; i++){
        int u,v; ll w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dist[1]=1; dfs(1,0); int A=far;
    dist[A]=0; dfs(A,0);

    ll ans=dist[far];

    for(int i=1 ; i<=n ; i++) if(dist[i]==ans) B.push_back(i);

    for(int &v : B){
        for(int i=v ; i ; i=f[i]){
            if(f[i]) cnt[{f[i],i}]++;
        }
    }

    ll sum=0;

    for(auto& [u,cur] : cnt){
        if(cur==B.size()) sum++;
    }

    cout<<ans<<'\n';
    cout<<sum;

    return 0;
}