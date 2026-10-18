#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll =long long;

void solve()
{
    ll s=0;

    int n; cin>>n;
    vector<ll> v(n);
    for(auto &nx : v){
        cin>>nx;
        s+=nx;
    }

    for(int i=1 ; i<=n-1 ; i++){ v[i]=min(v[i],v[i-1]+1) ;}
    for(int i=n-2 ; i>=0 ; i--){ v[i]=min(v[i],v[i+1]+1) ;}
    for(auto &nx : v){ s-=nx ;}

    cout<<s<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}