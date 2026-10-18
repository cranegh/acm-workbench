#include<iostream>
#include<algorithm>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 2e6+9;
bitset<N> vis;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    vis[0]=1,vis[1]=1;
    for(int i=2 ; i<=n ; i++){
        if(!vis[i]) for(int j=2*i ; j<=n ; j+=i) vis[i]=1;
    }

    for(int i=1 ; i<=n ; i++) if(!vis[i]) cout<<i<<' ';
    
    return 0;
}