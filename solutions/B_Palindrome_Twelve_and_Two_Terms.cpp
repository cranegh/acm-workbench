#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    if(n==10){
        cout<<-1<<'\n';
        return;
    }

    int m = n%12;
    if(m!=10){
        cout<<m<<" "<<n-m<<'\n';
    }else{
        cout<<22<<" "<<n-m-12<<'\n';
    }

    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}