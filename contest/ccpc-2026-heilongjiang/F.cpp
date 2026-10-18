#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
   ll x; cin>>x;
   if(x==1) cout<<"I love Heilongjiang\n";
   else if(x==0) cout<<"I love CCPC\n";
   else cout<<"Error\n";

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}