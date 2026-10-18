#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> t(3);
    for(int i=0; i<3; i++) t[i] = a[i];
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());

    cout<<t[2]<<'\n';
    for(int i=3; i<n; i++){
        ll cur = a[i];
        if(cur >= t[0]){
            t[2] = t[1];
            t[1] = t[0];
            t[0] = cur;
        }else if(cur >= t[1]){
            t[2] = t[1];
            t[1] = cur;
        }else if(cur >= t[2]){
            t[2] = cur;
        }

        cout<<t[2]<<'\n';
    }

    return 0;
}
