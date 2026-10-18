#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll q,x; cin>>q>>x;
    vector<ll> cnt(x,0);
    ll mex = 0;
    for(int i=0 ; i<q ; i++){
        ll y; cin>>y;
        ll cur = y%x;
        cnt[cur]++;

        while(cnt[mex%x] > mex/x) mex++;
        cout<<mex<<'\n';
    }
    
    return 0;
}