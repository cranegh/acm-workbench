#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s; cin>>s;
    int len = s.length();

    string s1 = "W";
    string s2 = "B";

    while(s1.length()<len){
        if(s1[s1.length()-1]=='B') s1+="W";
        else if(s1[s1.length()-1]=='W') s1+="B";
    }

    while(s2.length()<len){
        if(s2[s2.length()-1]=='B') s2+="W";
        else if(s2[s2.length()-1]=='W') s2+="B";
    }

    int first = -1;
    int last = -1;
    for(int i=0 ; i<len ; i++){
        if(s[i]!=s1[i]){
            if(first==-1) first = i;
            last = i;
        }
    }

    int ans = 0;
    if(first == -1) ans = 0;
    else{
        ans = last - first + 1;
    }

    //cout<<ans<<'\n';

    //cout<<s2<<'\n';
    //cout<<first<<'\n';

    first = -1;
    last = -1;
    for(int i=0 ; i<len ; i++){
        if(s[i]!=s2[i]){
            if(first==-1) first = i;
            last = i;
        }
    }

    if(first == -1) ans = 0;
    else{
        ans = min(ans , last - first + 1);
    }
    
    cout<<ans;
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}