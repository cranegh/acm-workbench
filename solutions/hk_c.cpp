#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> p(n+1);
    int mx = 0;
    for(int i=1; i<=n; i++){
        cin>>p[i];
        mx = max(p[i],mx);
    }
    for(int i=1; i<=n; i++){
        if(p[i]==mx) cout<<i<<" ";
    }
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}