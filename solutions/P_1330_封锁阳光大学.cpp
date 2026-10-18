#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

const int N = 1e4+9;
vector<int> g[N];
int state[N];

int min_cnt=1e8;
int n,m;
int crab_cnt=0,nocrab_cnt=0;

bool dfs(int u, int cur_state){
    state[u]=cur_state;

    if(cur_state==1) crab_cnt++;
    else nocrab_cnt++;

    for(int i=0 ; i<g[u].size() ; i++){
        int v = g[u][i];

        int next_state;
        if(cur_state==1) next_state=2;
        else if(cur_state==2) next_state=1;

        if(state[v]==0) 
        {if(!dfs(v,next_state)) return false;}
        else if(state[v]!=next_state) return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int tt=0;

    for(int i=1 ; i<=n ; i++){
        if(state[i]==0){
            crab_cnt=0;
            nocrab_cnt=0;

            if(!dfs(i,1)){
                cout<<"Impossible";
                return 0;
            }

            tt+=min(crab_cnt,nocrab_cnt);
        }
    }

    cout<<tt;

    return 0;
}