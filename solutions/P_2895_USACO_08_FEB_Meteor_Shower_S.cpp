#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct point{
    int x,y;
};

const int N = 5e5+9;
int m,ans=-1;
int x[N],y[N],t[N];
int dx[5]={0,-1,0,0,1};
int dy[5]={0,0,-1,1,0};
bool end_r[310][310];
bool vis[310][310];
int nt[310][310];//到达该点的时间
vector<point> new_r[1010];//该时刻新增摧毁点

void bfs(int a,int b){
    queue<point> q;
    q.push({a,b});
    nt[a][b]=0;

    while(!q.empty()){
        point cur=q.front();
        if(!end_r[cur.x][cur.y]){
            ans=nt[cur.x][cur.y];
            break;
        }
        q.pop();
        
        for(int i=0 ; i<new_r[0].size() ; i++){
            for(int j=0 ; j<5 ; j++){
                int nx=new_r[0][i].x+dx[j];
                int ny=new_r[0][i].y+dy[j];
                vis[nx][ny]=true;
            }
        }

        int moment=nt[cur.x][cur.y];

        for(int i=0 ; i<new_r[moment+1].size() ; i++){
            for(int j=0 ; j<5 ; j++){
                int nx=new_r[moment+1][i].x+dx[j];
                int ny=new_r[moment+1][i].y+dy[j];
                vis[nx][ny]=true;
            }
        }

        for(int i=0 ; i<5 ; i++){

            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];

            if(vis[nx][ny]) continue;
            if(nx<0 || ny<0) continue; 

            nt[nx][ny]=moment+1;
            q.push({nx,ny});
            vis[nx][ny]=true;
        }
    }
}


int main(){
    cin>>m;
    
    for(int i=1 ; i<=m ; i++) cin>>x[i]>>y[i]>>t[i];

    for(int i=1 ; i<=m ; i++){
        new_r[t[i]].push_back({x[i],y[i]});
    }

    for(int i=1 ; i<=m ; i++)
    {
        for(int j=0 ; j<5 ; j++){
            int nx=x[i]+dx[j];
            int ny=y[i]+dy[j];
            end_r[nx][ny]=true;
        }
    }

    bfs(0,0);

    cout<<ans;

    return 0;
}