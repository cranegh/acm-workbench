#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m; 
const int N = 1000005;
vector<int> g[N];
int ind[N];

void init(){
    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1; i<=n; i++) ind[i] = 0;
}

void solve()
{
    cin>>n>>m;
    init();

    for(int i=0; i<m; i++){
        int l,r; cin>>l>>r;
        int len = r-l+1;
        vector<int> v(len);
        for(int k=0; k<len; k++) cin>>v[k];
        for(int k=0; k<len-1; k++){
            g[v[k]].push_back(v[k+1]);
            ind[v[k+1]]++;
        }
    }

    vector<int> ord;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1; i<=n; i++){
        if(ind[i]==0) pq.push(i);
    }

    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        ord.push_back(u);
        for(int v : g[u]){
            ind[v]--;
            if(ind[v]==0) pq.push(v);
        }
    }

    if(ord.size()!=n){
        cout<<-1<<'\n';
    }else{
        vector<int> p(n+1);
        for(int i=0; i<n; i++){
            p[ord[i]] = i+1;
        }

        for(int i=1; i<=n; i++){
            cout<<p[i]<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}