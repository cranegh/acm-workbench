#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 5e5+9;
bitset<N> vis;

void solve(){
    int n; cin>>n;

    vector<int> a(n+1);
    vector<int> ans(n+1);

    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++){
        if(a[i]==i){
            ans[i]=i;
            vis[i]=true;
        }
    }

    for(int i=n ; i>=1 ; i--){
        int cur=i;
        while(!vis[cur]) cur=a[cur];
        ans[i]=ans[cur];
        vis[i]=true;
    }

    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<' ';


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;

}