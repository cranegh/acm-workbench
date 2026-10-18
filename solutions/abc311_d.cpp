#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 205;
string s[N];
bool vis[N][N];
bool stop[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(stop[x][y]) return;
    stop[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x, ny = y;

        while(s[nx + dx[i]][ny + dy[i]] == '.'){
            nx += dx[i];
            ny += dy[i];

            vis[nx][ny] = true;
        }

        dfs(nx,ny);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;

    int n,m; cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>s[i];
    }

    vis[1][1] = true;
    dfs(1,1);

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(vis[i][j]) ans++;
        }
    }

    cout<<ans;
}