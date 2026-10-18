#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

int n;
int a[4][4];
int ans=1e8;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

void change(int &x){
    x^=1;
}

bool check()
{
    for(int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ; j++){
            if(!a[i][j]) return false;
        }
    }
    return true;
}

void dfs(int x, int y , int cnt){
    if(cnt>=ans) return;
     
    if(check()){
        ans=min(ans,cnt);
        return;
    }

    if(x>3) return;

    int ne_x = y==3 ? x+1 : x;
    int ne_y = y==3 ? 1 : y+1;

    dfs(ne_x,ne_y,cnt);

    change(a[x][y]);
    for(int i=0 ; i<4 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>3 || nx<1 || ny>3 || ny<1) continue;
        change(a[nx][ny]);
    }

    dfs(ne_x,ne_y,cnt+1);

    change(a[x][y]);
    for(int i=0 ; i<4 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>3 || nx<1 || ny>3 || ny<1) continue;
        change(a[nx][ny]);
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ; j++){
            cin>>a[i][j];
        }
    }

    dfs(1,1,0);

    cout<<ans;

      

    return 0;
}