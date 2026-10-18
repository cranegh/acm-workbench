#include<iostream>

using namespace std;

int n,m;
int map[25][25];
bool vis[25];

int max_s=0;

void dfs(int x,int s){
    if(s>max_s) max_s=s;

    for(int i=1 ; i<=n ; i++){
        if(map[x][i]>0 && !vis[i]){
            vis[i]=true;
            dfs(i,s+map[x][i]);
            vis[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1 ; i<=m ; i++){
        int x,y,w; cin>>x>>y>>w;
        map[x][y]=w;
        map[y][x]=w;
    }

    for(int i=1 ; i<=n ; i++){
        vis[i]=true;
        dfs(i,0);
        vis[i]=false;
    }
    
    cout<<max_s<<'\n';

    return 0;
}