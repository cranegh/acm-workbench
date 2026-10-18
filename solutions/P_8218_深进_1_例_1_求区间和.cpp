#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    vector<int> pre(n+1,0);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++) pre[i] = pre[i-1]+a[i];

    int m; cin>>m;
    for(int i=0 ; i<m ; i++){
        int l,r; cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}