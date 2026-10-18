#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    string ss = "";
    ss += s[0];

    for(int i=1; i<n; i++){
        if(s[i] != s[i-1]) ss += s[i];
    }

    int remove = 0;
    for(int i=1; i<n-1; i++){
        if(s[i] != s[i-1] && s[i] != s[i+1]) remove = max(remove,1);
        if(s[i-1] == s[i+1] && s[i]!=s[i-1]) remove = max(remove,2);
    }

    int ans = ss.length()-remove;

    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}