#include<iostream>

using namespace std;
using ll = long long;

const int N = 2e6+9;
ll pcpd[N];

ll gcd(ll a, ll b)
{
    while(b!=0){
        ll temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

void init()
{
    for(int i=1 ; i<N ; i++) pcpd[i]=1;

    for(int i=2 ; i<N ; i++){
        if(pcpd[i]==1) for(int j=i ; j<N ; j+=i) pcpd[j]*=i;
    }
}

void solve()
{
    ll a,b; cin>>a>>b;
    ll g=gcd(a,b);

    if(g==1) cout<<0<<'\n';
    else cout<<pcpd[g]<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();

    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}