#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    ll sum_d = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        int d; cin>>a[i]>>d;
        sum_d += 1ll*d;
    }

    sort(a.begin(),a.end());
    ll curf = 0;
    ll sum_f = 0;
    for(int x : a){
        curf += 1ll*x;
        sum_f += curf;
    }

    ll ans = sum_d - sum_f;
    cout<<ans;
    
    return 0;
}