#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 5e3+9;
vector<int> g[N];
int ind[N];

vector<int> ans_sort;

bitset<N> reach[N];

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

    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        ind[v]++;
    }

    topo_sort();

    for(int i=ans_sort.size()-1 ; i>=0 ; i--){
        int u=ans_sort[i];

        reach[u][u]=true;

        for(int &x : g[u]){
            reach[u]|=reach[x];
        }
    }

    for(int i=1 ; i<=n ; i++) cout<<reach[i].count()<<' ';

    return 0;
}