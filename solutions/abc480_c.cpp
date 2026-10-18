#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k,t; cin>>n>>k>>t;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    int m = 0;
    for(int i=0; i<n; i++){
        if(a[i] < t) m++;
    }
    cerr<<m<<'\n';

    if(m == 0){
        cout <<(t+k-1)/k<<'\n';
        return 0;
    }

    vector<ll> T;
    if(a[0] > 0) T.push_back(a[0]);
    for(int i=1; i<m; i++){
        ll d = a[i] - (a[i-1]+k);
        if(d > 0) T.push_back(d); 
    }
    if(t- (a[m-1]+k) > 0) T.push_back(t- (a[m-1]+k) );

    ll ans = 0;
    for(int i=0; i<T.size(); i++){
        ll cur = (T[i]+k-1)/k;
        cerr<<T[i]<<" "<<cur<<'\n';
        ans += cur;
    }
    
    cout<<ans<<endl;

    return 0;
}