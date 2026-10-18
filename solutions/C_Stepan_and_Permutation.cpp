#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,x,y; cin>>n>>x>>y;
    vector<ll> a(n+1);
    vector<ll> o(n+1);
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    bool pp = true;
    
    for(int i=1 ; i<=n ; i++){
        int j = a[i];
        int cur = abs(i-j);

        int g = gcd(x,y);
        if(cur%g!=0){
            pp = false;
            break;
        } 
    }

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";
    

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}