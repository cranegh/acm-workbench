#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l; cin>>n>>l;
    vector<int> d(n);
    for(int i=1 ; i<n ; i++) cin>>d[i];

    vector<int> p(n+1,0);
    vector<ll> cnt(l,0);
    for(int i=1 ; i<=n ; i++){
        p[i] = (p[i-1] + d[i-1])%l;
        cnt[p[i]]++;
    }
    
    ll ans = 0;
    int dd = l/3;
    int a = 0;
    if(l%3==0){
        while(a+2*dd<l){
            int b = a+dd, c = b+dd;
            ans += cnt[a]*cnt[b]*cnt[c];
            a++;
        }
    }else ans = 0;
    
    cout<<ans;
    
    return 0;
}