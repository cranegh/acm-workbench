#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s;
    while(cin>>s){
        int len = s.length();
        cout<<s;
        if(s[len-1]=='n') cout<<"g";
        cout<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}