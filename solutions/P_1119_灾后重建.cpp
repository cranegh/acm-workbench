#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 220;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int t[N];

ll d[N][N];
int n,m; 

void updata(int k)
{
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(d[i][k]!=inf && d[k][j]!=inf && d[i][k]+d[k][j]<d[i][j]) d[j][i]=d[i][j]=d[i][k]+d[k][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=0 ; i<n ; i++) cin>>t[i];

    memset(d,0x3f,sizeof(d));
    for(int i=0 ; i<n ; i++) d[i][i]=0;

    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        ll w; cin>>w;
        d[u][v]=w;
        d[v][u]=w;
    }

    int q; cin>>q;

    int cur=0;
    for(int i=0 ; i<q ; i++){
        int x,y,tt; cin>>x>>y>>tt;
        while(t[cur]<=tt && cur<n){
            updata(cur);
            //for(int i=0 ; i<n ; i++) for(int j=0 ; j<n ; j++) cout<<d[i][j]<<" ";
            //cout<<'\n';
            cur++;
        }
        if(t[x]>tt || t[y]>tt) cout<<-1<<'\n';
        else{
            if(d[x][y]==inf) cout<<-1<<'\n';
            else cout<<d[x][y]<<'\n';
        }
    }


    return 0;
}