#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s,t; cin>>s>>t;
    vector<int> cnta(26,0);
    vector<int> cntb(26,0);
    for(int i=0 ; i<n ; i++) cnta[s[i]-'a']++;
    for(int i=0 ; i<n ; i++) cntb[t[i]-'a']++;
    
    for(int i=0 ; i<26 ; i++){
        if(cnta[i]!=cntb[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}