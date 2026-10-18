#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    string ans = "";

    for(int i=0 ; i<s.size() ; i++) if('0'<=s[i] && s[i]<='9') ans+=s[i];

    cout<<ans;
    
    return 0;
}