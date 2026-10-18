#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    s += '*';
    int mx = 0;
    int cur = 0;
    for(int i=0 ; i<=n ; i++){
        if(s[i]=='#') cur++;
        else if(s[i]=='*'){
            mx = max(mx,cur);
            cur=0;
        }
    }

    int ans;
    if(mx%2==0) ans = mx/2;
    else ans = mx/2+1;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}