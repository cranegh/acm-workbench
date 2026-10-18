#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,x,y,z; cin>>n>>x>>y>>z;

    int t1 = 0;
    int tt1 = 0;

    while(tt1<n){
        tt1+=(x+y);
        t1++;
    }
    
    int t2 = 0;
    int tt2 = 0;

    while(tt2<n){
        if(t2<z) tt2+=x;
        else tt2+=(x+10*y);
        t2++;
    }

    int ans = min(t1,t2);
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}