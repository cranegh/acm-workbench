#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool vis[410][410];

struct pos{
    int x,y,w;
};

void solve()
{
    memset(vis,0,sizeof(vis));

    int n; cin>>n;
    vector<int> x(n+1);
    vector<int> y(n+1);
    for(int i=1 ; i<=n ; i++) cin>>x[i]>>y[i];

    int ans = -1;

    queue<pos> q;
    q.push({0,0,0});
    
    while(!q.empty()){
        auto [cx,cy,cw] = q.front();
        q.pop();
        
        if(cx==0 && cy==0 && cw!=0){
            ans = cw;
            break;
        }

        for(int i=1 ; i<=n ; i++){
            int nx = cx + x[i];
            int ny = cy + y[i];

            if(nx<-200 || nx>200 || ny<-200 || ny>200 || vis[nx+200][ny+200]) continue;

            vis[nx+200][ny+200] = true;
            q.push({nx,ny,cw+1});
        }

    }

    cout<<ans<<'\n';

}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

}