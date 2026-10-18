#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int m,r,c; cin>>m>>r>>c;
    int q = (c-m)/(r+m);
    double ans = 0;
    int off = 3;
    for(int i=max(0,q-off) ; i<=q+off ; i++){
        double part1 = (i+1)*m;
        double part2 = max(c,(i+1)*m+i*r);
        double res = part1/part2;
        ans = max(ans,res);
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cout<<fixed<<setprecision(12);
    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}