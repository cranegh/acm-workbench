#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll px,py,qx,qy,rx,ry,sx,sy; cin>>px>>py>>qx>>qy>>rx>>ry>>sx>>sy;

    bool p1 = (rx-sx)*(py-qy) == (px-qx)*(ry-sy);
    bool p2 = (((ry+sy)-(py+qy))*(py-qy) == -(px-qx)*((rx+sx)-(px+qx)));
    if(p1 && !p2) cout<<"No\n";
    else cout<<"Yes\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}