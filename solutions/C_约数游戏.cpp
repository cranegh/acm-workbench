#include<iostream>

using namespace std;
using ll = long long;

ll count_prime(ll n){
    ll cnt=0;
    for(int i=2 ; i*i<=n ; i++){
        while(n%i==0){
            cnt++;
            n/=i;
        }
    }
    if(n>1) cnt++;
    return cnt;
}

void solve(){
    ll a,b; cin>>a>>b;
    
    ll cnta=count_prime(a),cntb=count_prime(b);

    if(cnta==cntb) cout<<"No\n";
    else cout<<"Yes\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}