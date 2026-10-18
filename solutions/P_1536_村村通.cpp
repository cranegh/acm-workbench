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

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;
    while(cin>>n){
        if(n==0) break;

        for(int i=1 ; i<=n ; i++) pre[i]=i;

        int m; cin>>m;
        for(int i=1 ; i<=m ; i++){
            int u,v; cin>>u>>v;
            merge(u,v);
        }

        int num=0;
        for(int i=1 ; i<=n ; i++) if(pre[i]==i) num++;
        
        int ans=0;
        if(num>1) ans=num-1;

        cout<<ans<<'\n';
    }
    return 0;
}