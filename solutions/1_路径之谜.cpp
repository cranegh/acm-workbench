#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 20+9;

bool vis[N][N];

int cntx[N];
int cnty[N];

int ansx[N];
int ansy[N];

int n;
int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};

bool check()
{
    for(int i=1 ; i<=n ; i++){
        if(cntx[i]!=ansx[i]) return false;
        if(cnty[i]!=ansy[i]) return false;
    }

    return true;
}

int process(pair<int,int> i)
{
    int res=0;

    int x=i.first;
    int y=i.second;

    res+=(x-1)*n;
    res+=(y-1);

    return res;
}

void dfs(int x , int y , vector<pair<int,int>> &v){
    if(x==n && y==n){
        if(check()){
            for(auto &i : v){
                cout<<process(i)<<' ';
            }
            exit(0);
        }
        return;
    }

    for(int i=0 ; i<4 ; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<1 || nx>n || ny<1 || ny>n) continue;
        if(vis[nx][ny]) continue;
        if(cntx[nx]+1>ansx[nx] || cnty[ny]+1>ansy[ny]) continue;

        vis[nx][ny]=true;
        cntx[nx]++;
        cnty[ny]++;
        v.push_back({nx,ny});
        dfs(nx,ny,v);
        v.pop_back();
        cntx[nx]--;
        cnty[ny]--;
        vis[nx][ny]=false;
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    for(int i=1 ; i<=n ; i++) cin>>ansy[i];
    for(int i=1 ; i<=n ; i++) cin>>ansx[i];

    vector<pair<int,int>> v;
    v.push_back({1,1});
    cntx[1]++;
    cnty[1]++;
    vis[1][1]=true;
    dfs(1,1,v);

    return 0;
}