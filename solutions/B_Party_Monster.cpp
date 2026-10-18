#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    int n1=0,n2=0;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='(') n1++;
        if(s[i]==')') n2++;
    }

    if(n1==n2) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}