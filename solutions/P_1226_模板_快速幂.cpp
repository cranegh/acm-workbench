#include<iostream>

using namespace std;
using ll = long long;

ll a,b,p;

ll qpow(ll a , ll n)
{
    ll res=1;
    while(n>0){
        if(n%2==1) res=(res*a)%p;
        a=(a*a)%p;
        n/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>a>>b>>p;

    cout<<a<<"^"<<b<<" mod "<<p<<"=";

    ll ans=qpow(a,b)%p;

    cout<<ans;

    return 0;
}