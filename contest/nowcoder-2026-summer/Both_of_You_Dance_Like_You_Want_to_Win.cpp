#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    int x = a.size();
    if(x<=3) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}