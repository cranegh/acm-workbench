#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int MOD = 19260817;

ll qpow(ll a , ll n){
    ll res=1;
    while(n>0){
        if(n%2==1) res*=a;
        a*=a;
        n/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int a,b; cin>>a>>b;

    ll ans=a*qpow(b,MOD-2);
    cout<<ans;
    
    return 0;
}