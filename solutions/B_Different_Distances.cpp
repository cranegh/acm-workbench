#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cout<<i<<" ";
    for(int i=1 ; i<=n ; i++) cout<<i<<" "<<i<<" ";
    for(int i=n-1 ; i>=1 ; i--) cout<<i<<" ";
    cout<<n<<" ";
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}