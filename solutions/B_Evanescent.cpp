#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int ans = 1;
    bool reduce1 = false;
    bool reduce2 = false;

    char Previous_ch = s[0];
    for(int i=1 ; i<n ; i++){
        char cur_ch = s[i];
        if(i+1<n){
            if(cur_ch!=Previous_ch && cur_ch!=s[i+1]){
                reduce1 = true;
                if(Previous_ch == s[i+1]) reduce2 = true;
            }
        }

        if(cur_ch != Previous_ch) ans++;
        Previous_ch = cur_ch;
    }

    if(reduce1) ans--;
    if(reduce2) ans--;
    
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}