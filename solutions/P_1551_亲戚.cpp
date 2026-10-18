#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

const int N = 5e3+9;
int pre[N];

int root(int x){
    if(pre[x]==x) return x;
    else return pre[x]=root(pre[x]);
}

void merge(int u,int v){
    if(root(u)!=root(v)) pre[root(u)]=root(v);
}

bool check(int u,int v){
    if(root(u)!=root(v)) return 0;
    else return 1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m,p; cin>>n>>m>>p;

    for(int i=1 ; i<=n ; i++) pre[i]=i;

    for(int i=0 ; i<m ; i++){
        int u,v; cin>>u>>v;
        merge(u,v);
    }

    for(int i=0 ; i<p ; i++){
        int u,v; cin>>u>>v;
        if(check(u,v)) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}