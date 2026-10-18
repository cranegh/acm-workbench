#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
int p[N], d[N];

void solve()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i];
    for(int i=1; i<=n; i++) cin>>d[i];

    vector<bool> vis(n+1,false);
    vector<int> belong(n+1,0);
    vector<int> sz(n+1,0);

    int tot = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        int cur = i;
        int len = 0;
        tot++;

        while(!vis[cur]){
            vis[cur] = true;

            belong[cur] = tot;
            cur = p[cur];
            len++;
        }
        sz[tot] = len;
    }

    vector<bool> used(n+1);
    int ans = 0;
    for(int i=1; i<=n; i++){
        int idx = belong[d[i]];
        if(!used[idx]){
            ans += sz[idx];
            used[idx] = true;
        }

        cout<<ans<<" ";
    }

    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}