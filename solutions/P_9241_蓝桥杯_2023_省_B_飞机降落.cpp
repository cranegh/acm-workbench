#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

int t[13],d[13],l[13];
bitset<13> vis;
int n;
bool ok=false;

void dfs(int tt , int dep){
    if(dep==n){
        ok=true;
        return;
    }

    for(int i=1 ; i<=n ; i++){
        if(vis[i]) continue;
        if(t[i]+d[i]<tt) continue;

        vis[i]=true;
        dfs(max(tt,t[i])+l[i],dep+1);
        vis[i]=false;
    }
}

void solve(){
    cin>>n;
    for(int i=1 ; i<=n ; i++) vis[i]=false;

    for(int i=1 ; i<=n ; i++){
        cin>>t[i]>>d[i]>>l[i];
    }

    ok=false;
    dfs(0,0);
    if(ok==true){
        cout<<"YES\n";
        return;
    }
    
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();
    

    return 0;
}