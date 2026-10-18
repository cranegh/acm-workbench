#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s1; cin>>s1;
    string s2 = "fjcpc";

    string s = s2 + "@" + s1;
    vector<int> pi(s.length(),0);
    int ans = 0;
    for(int i=1; i<s.length(); i++){
        int len = pi[i-1];
        while(len && s[len]!=s[i]){
            len = pi[len-1];
        }
        if(s[len]==s[i]){
            pi[i] = len+1;
        }
        if(pi[i] == 5) ans++;
    }

    cout<<ans;
    
    return 0;
}