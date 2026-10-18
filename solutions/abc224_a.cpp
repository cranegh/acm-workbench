#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    int len = s.length();

    string ans = s.substr(len-2,2);
    if(ans == "er") cout<<"er";
    else cout<<"ist";
    
    return 0;
}