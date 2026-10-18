#include<bits/stdc++.h> 

using namespace std;
using ll = long long;

const int N = 1510;

int n;
ll A[N][N];
vector<int> e[N];

vector<int> findMatching(){
    vector<int> match(n,-1),vis(n),link(n),f(n),dep(n);

    auto find = [&](int u){
        while(f[u] != u)
            u = f[u] = f[f[u]];
        return u;
    };

    auto lca = [&](int u, int v){
        u = find(u);
        v = find(v);
        while(u!=v){
            if(dep[u]<dep[v])
                swap(u,v);
            u = find(link[match[u]]);
        }
        return u;
    };

    queue<int> que;
    auto blossom = [&](int u, int v, int p){
        while(find(u) != p){
            link[u] = v;
            v = match[u];
            if(vis[v]==0){
                vis[v] = 1;
                que.push(v);
            }
            f[u] = f[v] = p;
            u = link[v];
        }
    };

    auto augment = [&](int u){
        
        while(!que.empty())
            que.pop();

        iota(f.begin(),f.end(),0);

        fill(vis.begin(),vis.end(),-1);

        que.push(u);
        vis[u] = 1;
        dep[u] = 0;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto v : e[u]){
                if(vis[v] == -1){

                    vis[v] = 0;
                    link[v] = u;
                    dep[v] = dep[u] + 1;

                    if(match[v] == -1){
                        for(int x=v, y=u, temp ; y!=-1 ; x=temp, y = x == -1 ? -1 : link[x]){
                            temp = match[y];
                            match[x] = y;
                            match[y] = x;
                        }
                        return;
                    }

                    vis[match[v]] = 1;
                    dep[match[v]] = dep[u] + 2;
                    que.push(match[v]);

                }else if(vis[v]==1 && find(v) != find(u)){
                    int p = lca(u,v);
                    blossom(u,v,p);
                    blossom(v,u,p);
                }
            }
        }

    };

    auto greedy = [&](){
        for(int u=0 ; u<n ; ++u){
            if(match[u] != -1)
                continue;
            for(auto v : e[u]){
                if(match[v] == -1){
                    match[u] = v;
                    match[v] = u;
                    break;
                }
            }
        }
    };

    greedy();

    for(int u=0 ; u<n ; ++u)
        if(match[u]==-1)
            augment(u);

    return match;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=i ; j<=n ; j++){
            cin>>A[i][j];
            e[i].push_back(j);
            e[j].push_back(i);
        }
    }

    
    return 0;
}