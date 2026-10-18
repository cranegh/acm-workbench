#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
vector<int> g[N];
vector< pair<int,int> > edge;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int ans = 0;
    int n,m; cin>>n>>m;

    if(m==2){
        cout<<-1<<'\n';
        return 0;
    }

    set<int> used;

    map< pair<int,int>,int > cnt;
    for(int i=0; i<n; i++){
        int u,v; cin>>u>>v;
        if(u>v) swap(u,v);

        cnt[{u,v}]++;
        if(cnt[{u,v}]==2){
            used.insert(u);
            used.insert(v);
            edge.push_back({u,v});
        }
    }

    if(m>used.size()){
        cout<<1<<'\n';
        int x = 1;
        while(used.count(x)){
            x++;
        }
        cout<<x;
        return 0;
    }

    for(auto [u,v] : edge){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=m; i++){
        if(g[i].size()<m-1){
            cout<<2<<'\n';
            map<int,bool> mp;
            for(int &x : g[i]){
                mp[x] = true;
            }
            int yy = 0;
            for(int j=1; j<=m; j++){
                if(j==i) continue;
                if(mp.find(j)==mp.end()){
                    yy = j;
                    break;
                }
            }
            cout<<i<<" "<<yy<<'\n';
            return 0;
        }
    }

    cout<<3<<'\n';
    cout<<"1 2 3"; 

    return 0;
}