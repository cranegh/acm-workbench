#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const ll INF = 3e18+9;

const int N = 305;
ll d[N][N];

int n;

void floyd(){
    for(int i=1 ; i<=n ; i++) d[i][i]=0;

    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    memset(d,0x3f,sizeof(d));
    int m,q; cin>>n>>m>>q;
    for(int i=0 ; i<m ; i++){
        int u,v; ll w; cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
    }

    floyd();

    for(int i=0 ; i<q ; i++){
        int u,v; cin>>u>>v;
        if(d[u][v]>=INF) cout<<-1<<'\n';
        else cout<<d[u][v]<<'\n';
    }

    return 0;
}