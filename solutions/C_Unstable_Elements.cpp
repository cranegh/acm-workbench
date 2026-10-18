#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n);
    vector<int> cnt(n+1,0);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cnt[a[i]]++;
    ll sum = n;

    int ans = 0;
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    int len = 0;
    for(int i=0; i<=n; i++){
        if(cnt[i]>0) len++;
    }

    ll remove = 0;
    while(len>0){
        ll cur = sum-k;
        if(cur > 0){
            if(cur%len == 0 && cur/len<cnt[len-1]-remove ) ans++;
        }else{
            if(abs(cur)%len == 0) ans++;
        }
        ll add_remove = cnt[len-1]-remove;
        sum -= len*add_remove;
        remove += add_remove;
        len--;
        while(len>0 && cnt[len-1]==remove) len--;
    }

    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}