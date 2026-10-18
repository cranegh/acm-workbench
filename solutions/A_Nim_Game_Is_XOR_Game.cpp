#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
    int ans = 0;
    int X = 0;
    for(int &i : a) X^=i;

    if(n == 1){
        ans = 0;
    }else if(n >= 2){
        if(X == 0) ans = 1;
        else{
            int p = 0;
            for(int i=3; i>=0; i--){
                if(X>>i){
                    p = i;
                    break;
                }
            }
            for(int& x : a){
                if(x & (1<<p)) ans++;
            }
        }
    }
    cout<<ans<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}