#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> p(n+1);
    for(int i=1 ; i<=n ; i++) cin>>p[i];

    vector<int> ct(n+2,0);
    for(int i=1 ; i<=n ; i++){
        if(i<p[i]) ct[p[i]]++;
    }

    int ans=0;
    int curf=0;
    for(int x=1 ; x<=n+1 ; x++){
        curf+=ct[x-1];
        int cur=x-1-curf;
        ans=max(ans,cur);
    }

    cout<<ans;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}