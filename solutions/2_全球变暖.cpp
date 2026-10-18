#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const int N = 1010;
char grid[N][N];
bool vis[N][N];

int ans=0;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

struct point{
    int x,y;
};

void bfs(int x, int y){
    queue<point> q;
    q.push({x,y});
    bool sur = false;

    while(q.size()){
        point cur = q.front(); q.pop();

        if(vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y]=true;
        
        bool inland=true;
        for(int i=0 ; i<4 ; i++){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];

            if(grid[nx][ny]=='.') inland=false;

            if(grid[nx][ny]=='#' && !vis[nx][ny]) q.push({nx,ny});
        }

        if(inland) sur = true;
    }

    if(!sur) ans++;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin>>grid[i][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(grid[i][j]=='#' && !vis[i][j]) bfs(i,j);
        }
    }

    cout<<ans;

    return 0;
}