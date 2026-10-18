#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll health = 0;
    int ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0 ; i<n ; i++){
        if(a[i]>=0){
            ans++;
            health += a[i];
        }else{
            if(health+a[i]>=0){
                health += a[i];
                pq.push(a[i]);
                ans++;
            }else{
                if(!pq.empty() && a[i]>pq.top()){
                    health -= pq.top();
                    health += a[i];
                    pq.pop();
                    pq.push(a[i]);
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T=1; //cin>>T;
    while(T--) solve();

    return 0;
}