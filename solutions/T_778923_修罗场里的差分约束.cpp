#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5000+5;
const int INF = 0x3f3f3f3f;

// 建图：差分约束统一转化为 x_v <= x_u + w  → 有向边 u→v 权 w
vector<pair<int,int>> g[N];  // g[u] = {v, w}
int dist[N], cnt[N];         // cnt[v] = 从超级源点到 v 的最短路经过的边数
bool inq[N];

void solve()
{
    int n,m; cin>>n>>m;

    // 1. 读入约束，转化为有向边
    for(int i=0 ; i<m ; i++){
        int op,a,b,c; cin>>op;
        if(op==1){
            cin>>a>>b>>c;
            // x_a - x_b >= c  →  x_b <= x_a - c  → 边 a→b, 权 -c
            g[a].push_back({b, -c});
        }
        else if(op==2){
            cin>>a>>b>>c;
            // x_a - x_b <= c  →  x_a <= x_b + c  → 边 b→a, 权 c
            g[b].push_back({a, c});
        }
        else{ // op==3
            cin>>a>>b;
            // x_a = x_b  →  x_a <= x_b + 0, x_b <= x_a + 0
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }

    // 2. 超级源点 0 向所有点连权 0 的边
    for(int i=1 ; i<=n ; i++) g[0].push_back({i, 0});

    // 3. SPFA 判负环
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    inq[0] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = 0;

        for(auto [v,w] : g[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                // 共 n+1 个点(含超级源), 最短路最多走 n 条边; 超过说明有负环
                if(cnt[v] > n){
                    cout<<"No\n";
                    return;
                }
                if(!inq[v]){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }

    cout<<"Yes\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}
