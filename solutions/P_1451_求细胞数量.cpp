#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

int n,m;

char grid[105][105];
bool vis[105][105];

struct point{
    int x,y;
};

int ans=0;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void bfs(int x, int y){
    queue<point> q;
    q.push({x,y});
    vis[x][y]=true;

    while(!q.empty()){
        point cur = q.front(); q.pop();

        for(int i=0 ; i<4 ; i++){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];

            if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
            if(grid[nx][ny]=='0') continue;
            if(vis[nx][ny]) continue;

            q.push({nx,ny});
            vis[nx][ny]=true;
        }
    }

    ans++;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin>>grid[i][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(!vis[i][j] && grid[i][j]!='0') bfs(i,j);
        }
    }

    cout<<ans;
    
    return 0;
}