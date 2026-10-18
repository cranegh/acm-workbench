#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct point{
    int x,y;
};

const int N = 210;
int k[N],ans[N];

int n,a,b;
int dx[2];

void bfs(int a){
    queue<int> q;
    q.push(a);
    ans[a]=0;

    while(!q.empty()){
        int cur=q.front();
        if(cur==b) break;
        q.pop();

        dx[0]=k[cur];
        dx[1]=-k[cur];

        for(int i=0 ; i<2 ; i++){
            int nx=cur+dx[i];

            if(nx<1 || nx>n) continue;
            if(ans[nx]!=-1) continue;

            ans[nx]=ans[cur]+1;
            q.push(nx);
        }
    }

}


int main(){
    cin>>n>>a>>b;

    for(int i=1 ; i<=n ; i++) cin>>k[i];

    memset(ans,-1,sizeof(ans));

    bfs(a);

    cout<<ans[b];

    return 0;
}