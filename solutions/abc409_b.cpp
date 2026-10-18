#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<ll> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];

    ll mxx = 0;
    for(int i=0 ; i<=n ; i++){
        int x = i;
        int cnt = 0;
        for(int j=0 ; j<n ; j++){
            if(a[j]>=x) cnt++;
        }
        if(cnt>=x){
            if(x>mxx) mxx = x;
        }
    }

    cout<<mxx<<'\n';
    
    return 0;
}