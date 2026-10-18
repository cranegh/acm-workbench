#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    vector<int> d(n+1,0);
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='a') d[i+1] = 1;
        else if(s[i]=='b') d[i+1] = -1;
    }

    vector<int> pre(n+1,0);
    for(int i=1 ; i<=n ; i++) pre[i] = pre[i-1] + d[i];

    int S = pre[n];

    int ans = n;
    unordered_map<int,int> ump;
    ump[0] = 0;

    for(int i=1 ; i<=n ; i++){
        ump[pre[i]] = i;
        int cur = pre[i] - S;
        if(ump.count(cur)==0) continue;
        else ans = min(ans,i-ump[cur]);
    }

    if(ans==n) ans = -1;
    cout<<ans<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}