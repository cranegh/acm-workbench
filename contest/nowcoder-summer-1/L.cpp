#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
const int dx[5] = {0, -1, 1, 0, 0};
const int dy[5] = {0, 0, 0, -1, 1};
int T;
int n, m;
char m1[maxn][maxn], m2[maxn][maxn], mp[maxn][maxn];
bool vis[maxn][maxn];
bool flag = false;
void dfs(int x, int y, char cur, bool mj){
    if(flag) return;
    if(x == n && y == m){
        if(cur == 'P' || cur == 'N' && !mj && mp[x][y] == 'B') flag = true;
        return;
    };
    for(int i = 1; i <= 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx  < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[nx][ny] == '#') continue;
        if(mp[nx][ny] == 'B' || mp[nx][ny] == 'P' && cur == 'N' || mp[nx][ny] == 'N' && cur == 'P'){
            char nxt;
            if(cur == 'N') nxt = 'P';
            else nxt = 'N';
            vis[nx][ny] = 1;
            dfs(nx, ny, nxt, mj);
            vis[nx][ny] = 0;
        }
    }
    if(!mj && mp[x][y] == 'B'){
        for(int i = 1; i <= 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx  < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || mp[nx][ny] == '#') continue;
            if(mp[nx][ny] == 'B' || mp[nx][ny] == 'P' && cur == 'P' || mp[nx][ny] == 'N' && cur == 'N'){
                vis[nx][ny] = 1;
                dfs(nx, ny, cur, true);
                vis[nx][ny] = 0;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        flag = false;
        cin >> n >> m;
        for(int mod = 1; mod <= 2; mod++)
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++){
                    if(mod == 1) cin >> m1[i][j];
                    else cin >> m2[i][j];
                }
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                vis[i][j] = false;
                if(m1[i][j] == '.' && m2[i][j] == '#') mp[i][j] = 'N';
                else if(m1[i][j] == '#' && m2[i][j] == '.') mp[i][j] = 'P';
                else if(m1[i][j] == '.' && m2[i][j] == '.') mp[i][j] = 'B';
                else mp[i][j] = '#';
            }
        if(mp[n][m] == 'N'){
            cout << "NO" << endl;
            continue;
        }
        vis[1][1] = true;
        dfs(1, 1, 'N', false);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}