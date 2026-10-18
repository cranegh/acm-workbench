#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e5+9;
bitset<N> vis;
vector<int> v;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    vis[0]=1,vis[1]=1;
    for(int i=1 ; i<=N ; i++){
        if(!vis[i]) for(int j=2*i ; j<=N ; j+=i) vis[j]=1;
    }
    for(int i=1 ; i<=N ; i++){
        if(!vis[i]) v.
    }
    
    ll ans=0;
    int l,r; cin>>l>>r;
    for(int i=l ; i<=r ; i++){
        if(!vis[i]) ans++;
    }

    cout<<ans;
    
    return 0;
}