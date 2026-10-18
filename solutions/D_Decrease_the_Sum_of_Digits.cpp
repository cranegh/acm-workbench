#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll getsum(ll n){
    ll sum = 0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

void solve()
{
    ll n; int s; cin>>n>>s;
    ll p = 1;
    ll on = n;

    while(getsum(n)>s){ 
        int digit = (n/p)%10;
        ll add = (10-digit)%10*p;
        p*=10;
        n += add;
    }
    cout<<n-on<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _ = 1; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}