#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    string ans = "";
    for(char c : s){
        ans += c;
        ans += 'o';
    }
    ans.pop_back();

    cout<<ans;

    return 0;
}
