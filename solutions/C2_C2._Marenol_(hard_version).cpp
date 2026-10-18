#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string sa; cin>>sa; vector<int> a(n); for(int i=0 ; i<n ; i++) a[i] = sa[i]-'0';
    string sb; cin>>sb; vector<int> b(n); for(int i=0 ; i<n ; i++) b[i] = sb[i]-'0';

    bool ans = false;

    vector<int> positiona[2];
    vector<int> positionb[2];

    for(int i=0 ; i<n ; i++){
        if(a[i]==1){
            positiona[i%2].push_back(i);
        }
    }

    for(int i=0 ; i<n ; i++){
        if(b[i]==1){
            positionb[i%2].push_back(i);
        }
    }

    if(positiona[0].size()==positionb[0].size() && positiona[1].size()==positionb[1].size()) ans = true;
    
    if(!ans) cout<<"-1\n";
    else{
        ll res = 0;
        for(int i=0 ; i<2 ; i++){
            for(int j=0 ; j<positiona[i].size() ; j++){
                res += abs(positiona[i][j] - positionb[i][j]);

            }
        }
        cout<<res/2<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}