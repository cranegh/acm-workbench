#include<iostream>

using namespace std;
using ll = long long;

ll qpow(ll a , int n){
    ll res=1;
    while(n>=1){
        if(n%2==1){
            res*=a;
        }
        n/=2;
        a*=a;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    ll ans;
    for(int i=1 ; i<=30 ; i++){
        if(qpow(2,i)<=n) ans=qpow(2,i);
    }

    cout<<ans;

    return 0;
}