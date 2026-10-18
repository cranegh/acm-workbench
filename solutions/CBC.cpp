#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;
int a[N];
int ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    string ans = "";

    for(int i=0; i<s.length(); i++)
        if('A'<=s[i] && s[i]<='Z') ans += s[i];

    cout<<ans;

}