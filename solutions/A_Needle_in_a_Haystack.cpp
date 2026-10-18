#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s,t;
    cin>>s>>t;

    vector<int> ch(26,0);
    for(int i=0 ; i<t.length() ; i++) ch[t[i]-'a']++;
    for(int i=0 ; i<s.length() ; i++) ch[s[i]-'a']--;

    bool pp = true;
    for(int i=0 ; i<s.length() ; i++){
        if(ch[s[i]-'a']<0){
            pp = false;
            break;
        }
    }

    if(!pp){
        cout<<"Impossible\n";
        return;
    }

    int idx = 0;

    for(int i=0 ; i<26 ; i++){
        while(s[idx]-'a'<=i && idx<s.length()) cout<<s[idx++];
        for(int j=0 ; j<ch[i] ; j++) cout<<char('a'+i);
    }

    cout<<'\n';


    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}