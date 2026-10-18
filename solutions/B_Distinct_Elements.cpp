#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> b(n+1);
    for(int i=1 ; i<=n ; i++) cin>>b[i];

    ll new_val=1;
    vector<ll> a(n+1);
    a[1]=1;
    for(int i=1 ; i<n ; i++){
        int x=b[i+1]-b[i];
        if(x<i+1) a[i+1]=a[i-x+1];
        else if(x==i+1) a[i+1]=++new_val;
    }

    for(int i=1 ; i<=n ; i++) cout<<a[i]<<' ';
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}