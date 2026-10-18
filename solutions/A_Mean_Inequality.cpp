#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n; int m = 2*n;
    vector<ll> a(m);
    for(int i=0 ; i<m ; i++) cin>>a[i];
    sort(a.begin(),a.end());

    vector<ll> b(m);
    
    for(int i=0 ; i<n ; i++){
        b[2*i]=a[i];
        b[2*i+1]=a[m-i-1];
    } 

    for(int i=0 ; i<m ; i++) cout<<b[i]<<" ";
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}