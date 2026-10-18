#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#include<vector>

using namespace std;
using ll = long long;

const int N = 5e3+9;
const int MOD = 80112002;

vector<int> g[N];
int ind[N];
bitset<N> reach[N];

vector<int> ans_sort;

int n,m; 

void topo_sort(){
    queue<int> q;
    for(int i=1 ; i<=n ; i++){
        if(ind[i]==0) q.push(i);
    }

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        ans_sort.push_back(u);

        for(auto & v : g[u]){
            if(--ind[v]==0) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1 ; i<=m ; i++){
        int u,v; cin>>u>>v;
        g[v].push_back(u);
        ind[u]++;
    }

    topo_sort();

    for(int i=ans_sort.size()-1 ; i>=0 ; i--){
        int u = ans_sort[i];
        for(int &v : g[u]) reach[u]|=reach[v];
    }

    ll ans=0;
    for(int i=1 ; i<=n ; i++) ans=max(ans,(ll)reach[i].count());

    ans%=MOD;

    return 0;
}