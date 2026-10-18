#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> diff(n+1);
    for(int k=1; k<=n; k++){
        ll l = 1ll*a[k]*k;
        ll r = 1ll*(a[k]+1)*k-1ll;

        if(l<n) diff[l]--;
        if(r+1<n) diff[r+1]++;
    }

    vector<int> b;
    int cur = 0;
    for(int i=0; i<n; i++){
        cur += diff[i];
        if(cur >= 0) b.push_back(i);
    }

    cout<<b.size()<<'\n';
    for(int i : b) cout<<i<<" ";
    cout<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}