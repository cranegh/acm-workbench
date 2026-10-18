#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t; cin>>s>>t;
    int len = t.length();

    while(s.find(t) != string::npos){
        int pos = s.find(t);

        for(int i=pos; i<pos+len; i++){
            if('a'<=s[i] && s[i]<'z') s[i]++;
            else s[i] = 'a';
        }
    }

    cout<<s;

}