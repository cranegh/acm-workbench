#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

int n;

ll grid[1010][1010];
bool vis[1010][1010];

struct point{
    int x,y;
};

int ans_feng=0;
int ans_gu=0;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void bfs(int x,int y){
    queue<point> q;
    q.push({x,y});
    vis[x][y]=true;

    ll h=grid[x][y];
    bool higher=false;
    bool shorter=false;

    while(!q.empty()){
        point cur = q.front(); q.pop();

        for(int i=0 ; i<8 ; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx<1 || nx>n || ny<1 || ny>n) continue;

            if(grid[nx][ny]<h) higher=true;
            if(grid[nx][ny]>h) shorter=true;

            if(vis[nx][ny]) continue;
            
            if(grid[nx][ny]==h){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }

        }
    }
    if(shorter && !higher) ans_gu++;
    else if(higher && !shorter) ans_feng++;
    else if(!higher && !shorter) ans_gu++,ans_feng++;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin>>grid[i][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(!vis[i][j]) bfs(i,j);
        }
    }

    cout<<ans_feng<<' '<<ans_gu;
    
    return 0;
}