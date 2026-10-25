#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=1; i<=31; i++){
        if(i < n)
            a[i] = min(a[i],2*a[i-1]);
        else 
            a[i] = 2*a[i-1];
    }

    for(int i=0; i<q; i++){
        ll x; cin>>x;

        ll res = 0;
        for(int j=0; (1<<j)<=x ; j++){
            if(x & (1<<j)) res += a[j];

            res = min(res,a[j+1]);
        }
        
        cout<<res<<'\n';
    }

}