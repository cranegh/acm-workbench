#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
using ll = long long;

bool vis[7][7];
int cnt=0;
int n,m,t;
int sx,sy,fx,fy;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

void dfs(int x , int y){
    if(x==fx && y==fy){
        cnt++;
        return;
    }

    for(int i=0 ; i<4 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>n || ny>m || nx<=0 || ny<=0 ) continue;
        if(vis[nx][ny]==true) continue;

        vis[nx][ny]=true;
        dfs(nx,ny);
        vis[nx][ny]=false;
    }


} 

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>t;

    cin>>sx>>sy>>fx>>fy;

    for(int i=1 ; i<=t ; i++){
        int x,y; cin>>x>>y;
        vis[x][y]=true;
    }

    vis[sx][sy]=true;

    dfs(sx,sy);

    cout<<cnt;

    return 0;
}