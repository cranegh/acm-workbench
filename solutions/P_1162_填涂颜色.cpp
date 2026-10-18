#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
using ll = long long;

const int N = 35;
int a[N][N];
int n;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
 
struct point
{
    int x,y;
};

void bfs(int xx,int yy){
    queue<point> q;
    q.push({xx,yy});
    a[xx][yy]=3;

    while(!q.empty()){
        point head=q.front();
        q.pop();

        for(int i=0 ; i<4 ; i++){
            int nx=head.x+dx[i];
            int ny=head.y+dy[i];

            if(nx<0 || nx>n+1 || ny<0 || ny>n+1) continue;

            if(a[nx][ny]!=0) continue;

            a[nx][ny]=3;
            q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=n ; j++)
    cin>>a[i][j];

    bfs(0,0);

    for(int i=1 ; i<=n ; i++){
    for(int j=1 ; j<=n ; j++)
    {if(a[i][j]==3) cout<<"0 ";
    else if(a[i][j]==1) cout<<"1 ";
    else cout<<"2 ";}
    cout<<'\n';}
    
    return 0;

}