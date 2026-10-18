#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> h(n); for(int i=0 ; i<n ; i++) cin>>h[i];
    
    for(int i=0 ; i<n ; i++){
        ll curmx = 0;
        vector<ll> w1(n);
        vector<ll> w2(n);

        for(int j=0 ; j<n-1 ; j++){
            if(h[(i+j)%n]>curmx) curmx = h[(i+j)%n];
            w1[(i+j+1)%n] = curmx;
        }

        curmx = 0;
        for(int j=0 ; j<n-1 ; j++){
            if(h[(i-j-1+n)%n]>curmx) curmx = h[(i-j-1+n)%n];
            w2[(i-j-1+n)%n] = curmx;
        }

        ll res = 0;
        for(int j=0 ; j<n ; j++){
            if(i==j) continue;

            res += min(w1[j],w2[j]);
        }

        cout<<res<<" ";

    }

    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}