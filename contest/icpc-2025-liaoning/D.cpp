#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int a[110][3];
int n;
int ans = 3;

void dfs(int x, int mask){
    if(x > n){
        ans = min(ans,__builtin_popcount(mask));
        return;
    }

    for(int i=0; i<3; i++){
        if(a[x][i] && (mask & (1<<i))){
            dfs(x+1,mask);
            return;
        }
    }

    for(int i=0; i<3; i++){
        if(a[x][i]){
            dfs(x+1,mask|1<<i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
        }
    }

    dfs(1,0);

    cout<<ans;

    return 0;
}