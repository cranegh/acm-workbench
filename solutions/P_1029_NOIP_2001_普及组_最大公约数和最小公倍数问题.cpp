#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    ll temp=a%b;
    while(temp!=0){
        a=b;
        b=temp;
        temp=a%b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int x,y; cin>>x>>y;
    
    ll ans=0;
    for(int i=1 ; i<=y ; i++){
        if(x*y%i==0){
            int a=i,b=x*y/i;
            if(lcm(a,b)==y && gcd(a,b)==x) ans++;
        }
    }

    cout<<ans;
    
    return 0;
}