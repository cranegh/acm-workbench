#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int cnt = 0;
    for(int i=0 ; i<n-1 ; i++) if(s[i]!=s[i+1]) cnt++;

    if(cnt==1) cout<<2<<'\n';
    else cout<<1<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}