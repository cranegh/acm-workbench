#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 300005;
struct med{
    ll a,b;
    bool operator < (const med& u) const{
        return a < u.a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;

    vector<med> m(n);
    for(int i=0; i<n; i++) cin>>m[i].a>>m[i].b;

    ll sum = 0;
    for(int i=0; i<n; i++) sum += m[i].b;

    if(sum <= k){
        cout<<1;
        return 0;
    }
    
    sort(m.begin(),m.end());
    for(int i=0; i<n; i++){
        sum -= m[i].b;
        if(sum <= k){
            cout<<m[i].a+1;
            break;
        }
    }

    return 0;
}