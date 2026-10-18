#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    if(n==1){
        cout<<a[0]<<'\n';
        return;
    }

    sort(a.begin(),a.end());

    int ans1 = a[n-1];
    int ans2 = a[n-2];

    for(int i=n-3 ; i>=0 ; i--){
        int cur = a[i];
        int l = cur^ans1;
        int r = cur^ans2;

        if(l-ans1>r-ans2) ans1^=cur;
        else ans2^=cur;
    }
    int ans = ans1+ans2;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}