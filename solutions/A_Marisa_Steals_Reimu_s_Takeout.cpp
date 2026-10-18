#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> cnt(3);
    for(int i=0 ; i<n ; i++){
        int tt; cin>>tt;
        cnt[tt]++;
    }

    int ans = 0;
    ans += cnt[0];

    int aa = min(cnt[1],cnt[2]);
    cnt[1] -= aa;
    cnt[2] -= aa;

    ans += aa;
    ans += cnt[1]/3;
    ans += cnt[2]/3;

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}