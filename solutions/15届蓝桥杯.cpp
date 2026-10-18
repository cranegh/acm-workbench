#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;

struct edge{
    int v;
    ll w;
};

const int N = 1e5+9;
vector<edge> g[N];

ll f(ll x)
{
    ll res=(x*x+21*x)/2;
    return res;
}

ll max_len=0;
int p=0;

void dfs(int st, int f, ll cur_d)
{
    if(cur_d>max_len){
        max_len=cur_d;
        p=st;
    }

    if(g[st].size()==0) return;

    for(auto &[v,w] : g[st]){
        if(v==f) continue;
        dfs(v,st,cur_d+w);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<n ; i++){
        int p,q; ll d;
        cin>>p>>q>>d;
        g[p].push_back({q,d});
        g[q].push_back({p,d});
    }

    dfs(1,0,0);
    max_len=0;
    dfs(p,p,0);

    ll ans=f(max_len);

    cout<<ans;

    return 0;
}