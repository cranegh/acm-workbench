#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> f(n+1);
    for(int i=1 ; i<=n ; i++) cin>>f[i];

    vector<ll> d(n+1);
    for(int i=1 ; i<n ; i++) d[i]=f[i+1]-f[i];

    vector<ll> s(n+1,0);
    s[n] = (f[1]+f[n])/(n-1);

    for(int i=1 ; i<n ; i++) s[i]=(d[i]+s[n])/2;

    vector<ll> a(n+1);
    a[1]=s[1];
    for(int i=1 ; i<n ; i++) a[i+1]=s[i+1]-s[i];

    for(int i=1 ; i<=n ; i++) cout<<a[i]<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}