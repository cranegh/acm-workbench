#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6+9;

int pre[N];

int root(int x)
{
    if(pre[x]==x) return x;
    else return pre[x]=root(pre[x]);
}

void merge(int u, int v)
{
    pre[root(u)]=root(v);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    for(int i=1 ; i<=n ; i++) pre[i]=i;
    
    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        merge(u,v);
    }

    int cnt=0;
    for(int i=1 ; i<=n ; i++){
        if(pre[i]==i) cnt++;
    }

    int ans = m-(n-cnt);

    ans+=cnt-1;

    cout<<ans;

    return 0;
}