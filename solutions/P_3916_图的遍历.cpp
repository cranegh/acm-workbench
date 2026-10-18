#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5+9;
vector<int> g[N];
int ans[N];

void dfs(int x , int root){
    ans[x]=root;

    for(int i=0 ; i<g[x].size() ; i++){
        int next_node=g[x][i];

        if(ans[next_node]==0){
            dfs(next_node,root);
        }
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1 ; i<=m ; i++){
        int u,v; cin>>u>>v;
        g[v].push_back(u);
    }

    for(int i=n ; i>0 ; i--){
        if(ans[i]==0){
            dfs(i,i);
        }
    }

    for(int i=1 ; i<=n ; i++){
        cout<<ans[i]<<' ';
    }


    return 0;
}