#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;

    for(int i=0 ; i<n-k ; i++){
        if(s[i]=='1'){
            s[i]='0';
            if(s[i+k]=='0') s[i+k]='1';
            else if(s[i+k]=='1') s[i+k]='0';
        }
    }

    bool pp = true;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='1'){
            pp = false;
            break;
        }
    }

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";

    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}