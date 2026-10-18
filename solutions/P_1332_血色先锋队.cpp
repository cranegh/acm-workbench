#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

struct point{
    int x,y;
};

const int N = 510;
int t[N][N];

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

int n,m,a,b;
queue<point> q;

void bfs(){
    while(!q.empty()){
        point cur=q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx<=0 || ny<=0) continue;
            if(nx>n || ny>m) continue;
            if(t[nx][ny]!=-1 ) continue;

            t[nx][ny]=t[cur.x][cur.y]+1;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>a>>b;
    memset(t,-1,sizeof(t));

    for(int i=1 ; i<=a ; i++){
        int x,y; cin>>x>>y;
        t[x][y]=0;
        q.push({x,y});
    }

    bfs();
    
    for(int i=1 ; i<=b ; i++){
        int x,y; cin>>x>>y;
        cout<<t[x][y]<<'\n';
    }

    return 0;
}