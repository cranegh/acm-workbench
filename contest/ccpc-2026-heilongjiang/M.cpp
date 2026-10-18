#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;

void solve()
{
    int n,m; cin>>n>>m;
    if(m<=n/2){
        for(int i=1+m ; i<=n ; i++) cout<<i<<" ";
        for(int i=1 ; i<=m ; i++) cout<<i<<" ";
    }else{
        vector<int> p(n+1);
        for(int i=1 ; i<=n-m ; i++) p[i]=i+m;
        for(int i=m+1 ; i<=n ; i++) p[i]=i-m;
        for(int i=n-m+1 ; i<=m ; i++) p[i]=n+1-i;

        for(int i=1 ; i<=n ; i++) cout<<p[i]<<" ";
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}