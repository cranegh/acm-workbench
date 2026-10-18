#include<iostream>

using namespace std;

const int N = 2e5+9;
int pre[N];

int root(int x){
    if(pre[x]==x) return pre[x];
    else return pre[x]=root(pre[x]);
}

void merge(int x,int y){
    if(root(x)!=root(y)) pre[root(x)]=root(y);
}

void pd(int x,int y){
    if(root(x)==root(y)) cout<<"Y\n";
    else cout<<"N\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    for(int i=1 ; i<=n ; i++) pre[i]=i;

    while(m--){
        int z,x,y; cin>>z>>x>>y;
        if(z==1) merge(x,y);
        else if(z==2) pd(x,y);
    }

    return 0;
}