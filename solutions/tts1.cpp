#include<iostream>
#include<iomanip>

using namespace std;
using ll = long long;

ll qpow(ll a, int n){
    ll res=1;
    while(n>=1){
        if(n%2==1){
            res*=a;
        }
        a*=a;
        n/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll t; cin>>t;

    if(t<=3){
        cout<<t;
        return 0;
    }

    ll t_re=t-1;
    ll n1=0,n2=0;
    for(int i=1 ; i<=35 ; i++){
        if((3*(qpow(3,i-1)-1)+qpow(3,i))<=t_re) n1=i;
    }

    t_re-=3*(qpow(3,n1-1)-1)+qpow(3,n1);
    
    ll to_t=2*(n1-1)+1;
    for(int i=1 ; i<=n1 ; i++){
        if(qpow(3,i)<=t_re) n2=i;
    }

    while(n2>=1){
        if(t_re/qpow(3,n2)>0){
            to_t+=t_re/qpow(3,n2);
            t_re-=t_re/qpow(3,n2)*qpow(3,n2);
        }
        n2-=1;
    }

    ll ans=t_re+1+to_t;

    cout<<ans;

    return 0;

}