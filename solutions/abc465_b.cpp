#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y,l,r,a,b; cin>>x>>y>>l>>r>>a>>b;

    int tx = max(0,min(b,r)-max(l,a));
    int ty = b-a-tx;

    int ans = tx*x + ty*y;
    cout<<ans;
    
    return 0;
}