#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    bool ok = true;
    for(int i=0; i+1<n; i++){
        for(int j=0; j+1<n; j++){
            if(s[i][j] == '1'
            &&  s[i+1][j] == '0'
            && s[i][j+1] == '0'){
                ok = false;
                break;
            }
        }
    }

    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}