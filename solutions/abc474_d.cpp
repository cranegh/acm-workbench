#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    vector<int> k(n);
    for(int i=0; i<n; i++) k[i] = a[i] - b[i];

    ll need = 0;
    bool p = false;
    for(int i=0; i<n; i++){
        if(k[i]<0) need += -1ll*k[i];

        if(k[i]>0) p = true;
    }

    vector<ll> w(n);
    for(int i=0; i<n; i++){
        if(k[i]<=0) w[i] = 1;
        else if(k[i]>0) w[i] = need+1;
    }

    if(!p){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
        for(ll x : w){
            cout<<x<<" ";
        }
    }

    return 0;
}