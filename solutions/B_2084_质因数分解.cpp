#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n; cin>>n;
    for(ll i=2 ; n/i>=i ; i++){
        //cout<<1<<'\n';
        if(n%i==0){
            cout<<n/i;
            return 0;
        }
    }

    return 0;
}