#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
using ll = long long;

int n;
int v[15];
bool vis[15];

void dfs(int x){
    if(x==n+1){
        for(int i=1 ; i<=n ; i++){
            cout<<"    "<<v[i];
        }
        cout<<'\n';
        return;
    }

    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            v[x]=i;
            vis[i]=true;

            dfs(x+1);

            vis[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    dfs(1);

    return 0;
}