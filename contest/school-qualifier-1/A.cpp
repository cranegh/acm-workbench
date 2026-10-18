#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+5;
const ll MOD = 998244353;

int pre[N];
ll w[N];
bitset<N> used;

struct edge{
    int u,v;
}e[N];

int root(int x){
    if(x==pre[x]) return x;
    else return pre[x] = root(pre[x]);
}

void solve()
{
    int n,m; cin>>n>>m;

    for(int i=1 ; i<=m ; i++){
        cin>>e[i].u>>e[i].v;
    }

    //for(int i=1 ; i<=m ; i++) cout<<e[i].w<<" ";

    //sort(e+1,e+1+m);
    //for(int i=1 ; i<=m ; i++) cout<<e[i].w<<" ";

    w[1] = 2;
    for(int i=2 ; i<=m ; i++) w[i] = (w[i-1]*2)%MOD;

    for(int i=1 ; i<=n ; i++) pre[i] = i;
    int cnt = n;
 
    for(int i=m ; i>=1 ; i--){
        int u = e[i].u;
        int v = e[i].v;

        if(root(u)==root(v)){
            used[i] = true;
            continue;
        }
        
        if(cnt==2) continue;

        pre[root(u)] = root(v);
        used[i] = true;
        cnt--;


    }

    //cout<<cnt<<'\n';
    //for(int i=1 ; i<=m ; i++) if(used[i]) cout<<i<<" ";

    ll ans = 0;
    
    for(int i=1 ; i<=m ; i++){
        if(!used[i]) ans = (ans + w[i] )%MOD;
    }


    cout<<ans;

}

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int T=1; //cin>>T;
    while(T--) solve();

    return 0;
}
