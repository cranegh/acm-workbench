#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const int N = 1e5+9;
int n,k;
ll ans=0;

ll d[N];
bitset<N> vis;
int dx[2];

void bfs(int st){
    d[st]=0;
    queue<int> q;
    q.push(st);
    vis[st]=true;

    while(!q.empty()){
        int cur=q.front(); q.pop();

        for(int i=0 ; i<2 ; i++){
            int nx = (cur+dx[i])%n;

            if(vis[nx]) continue;

            d[nx]=d[cur]+1;
            ans=max(ans,d[nx]);
            vis[nx]=true;
            q.push(nx);

        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;

    dx[0]=1,dx[1]=k;
    bfs(1);

    cout<<ans;
    
    return 0;
}