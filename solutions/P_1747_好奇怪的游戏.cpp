#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

struct point{
    int x,y;
};

int a[23][23];

int dx[12]={2,2,1,-1,-2,-2,-2,-2,-1,1,2,2};
int dy[12]={1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};

void bfs(int x , int y){
    queue<point> q;
    q.push({x,y});
    a[x][y]=0;

    while(!q.empty()){
        point cur=q.front();
        q.pop();

        for(int i=0 ; i<12 ; i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(nx<=0 || ny<=0) continue;
            if(nx>22 || ny>22) continue;
            if(a[nx][ny]!=-1) continue;

            a[nx][ny]=a[cur.x][cur.y]+1;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    memset(a,-1,sizeof(a));

    int x1,y1; cin>>x1>>y1;
    int x2,y2; cin>>x2>>y2;

    bfs(1,1);
    cout<<a[x1][y1]<<'\n';

    cout<<a[x2][y2];

    return 0;
}