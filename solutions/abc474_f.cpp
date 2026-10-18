#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[N];
ll p[N],b[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=n; i>=1; i--){
        p[i] = 1;
        b[i] = -a[i];

        for(int j=i+i; j<=n; j+=i){
            p[i] -= p[j];
            b[i] -= b[j];
        }
    }
    
    ll A = 0;
    for(int i=1; i<=n; i++){
        if(A < a[i]) A = a[i];
    }

    ll l = A, r = INF;
    for(int i=1; i<=n; i++){
        if(p[i] > 0){
            ll cur = (-b[i]+p[i]-1)/p[i];
            l = max(l,cur);
        }
        else if(p[i] == 0){
            if(b[i] < 0){
                cout<<-1<<'\n';
                return 0;
            }
        }
        else if(p[i] < 0){
            ll cur = b[i]/(-p[i]);
            r = min(r,cur);
        }
    }

    if(l>r){
        cout<<-1<<'\n';
        return 0;
    }

    ll ans = l-a[1];
    cout<<ans<<'\n';

    return 0;
}