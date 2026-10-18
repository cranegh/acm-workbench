#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct point{
    int x,y;
};

const int N = 410;
int a[N][N];

int n,m,x,y;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};


void bfs(int x,int y){
    queue<point> q;
    q.push({x,y});
    a[x][y]=0;

    while(!q.empty()){
        point cur=q.front();
        q.pop();

        for(int i=0 ; i<8 ; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx<=0 || nx>n || ny<=0 || ny>m) continue;
            if(a[nx][ny]!=-1) continue;

            a[nx][ny]=a[cur.x][cur.y]+1;
            q.push({nx,ny});
        }
    }
}

int main(){
    cin>>n>>m>>x>>y;

    memset(a,-1,sizeof(a));

    bfs(x,y);

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}