#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll cnt[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    ll n = s.length();
    ll ans = 0;

    bool ok = false;

    for(int i=0; i<n; i++){
        if(cnt[s[i]-'a']) ok = true;
        ans += i-cnt[s[i]-'a'];
        cnt[s[i]-'a']++;
    }

    if(ok) ans++;
    cout<<ans<<endl;

    return 0;
}