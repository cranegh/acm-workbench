#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    
    int idx=n-1;
    int mn=a[idx]; 
    ll sum=0;
    
    cout<<'\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}