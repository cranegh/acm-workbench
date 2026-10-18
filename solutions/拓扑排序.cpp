#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e4+9;
vector<int> g[N];
int ind[N];

vector<int> ans;

int n,m; 

void topo_sort(){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1 ; i<=n ; i++){
        if(ind[i]==0) pq.push(i);
    }

    while (!pq.empty())
    {
        int u = pq.top(); pq.pop();
        ans.push_back(u);
        for(auto & v : g[u]){
            if(--ind[v]==0) pq.push(v);
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

    if(ans.size()!=n){
        cout<<-1;
    }else{
        for(int &i : ans) cout<<i<<' ';
    }
    
    return 0;
}