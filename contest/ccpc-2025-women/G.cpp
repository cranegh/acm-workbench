#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3e5+5;
bitset<N> vis;

void init()
{
    vis[1] = true;
    for(int i=2 ; i<300000+2 ; i++)
        if(!vis[i]) for(int j=2*i ; j<300000+2 ; j+=i) vis[j] = true;
}

void solve()
{
    int n,k; cin>>n>>k;

    int cnt = 0;
    vis[1] = true;
    for(int i=2 ; i<=n ; i++){
        if(!vis[i]){
            for(int j=2*i ; j<300000+2 ; j+=i) vis[j] = true;
            cnt++;
        }
    }

    if(cnt+1<k) cout<<"NO\n";
    else{
        cout<<"YES\n";
        int kk = 1;
        cout<<1<<" ";
        for(int i=2 ; i<=n ; i++){
            if(!vis[i]){
                cout<<i<<" ";
                kk++;
                if(kk==k)  break;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}