#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> p(n);
    for(int i=0 ; i<n ; i++) cin>>p[i];

    ll tt = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0 ; i<n ; i++){
        //cout<<p[i]<<" ";
        //cout<<tt<<'\n';
        if(!pq.empty() && p[i]>pq.top()){
            tt += p[i]-pq.top();
            pq.pop();
            pq.push(p[i]);
        }
        pq.push(p[i]);
    }

    cout<<tt;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}