#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; ll m; cin>>n>>m;
    vector<ll> a(n); for(ll &x : a) cin>>x;
    vector<ll> b(n-1); for(ll &x : b) cin>>x;

    vector<pair<ll, ll>> events;

    ll c = 0;
    ll tt_cost = 0;

    for(int i=0 ; i<n ; i++){
        ll d = (c-a[i]+m)%m;
        tt_cost += d;

        if(i%2==0){
            ll position = m-d;
            if(d!=0){
                events.push_back({position,-m});
            }
        }else{
            ll position = d+1;
            if(d!=m-1){
                events.push_back({position,m});
            }
        }

        if(i+1<n){
            c = (b[i]+m-c)%m;
        }
    }

    sort(events.begin(),events.end());

    ll cur_cost = tt_cost;
    ll ans = tt_cost;

    ll normoalChange = n%2;
    ll Previousposition = 0;

    for(int i=0 ; i<events.size() ; ){
        ll position = events[i].first;

        cur_cost += normoalChange*(position-Previousposition);
        ll cur_change = 0;

        int j = i;
        while(j<events.size() && events[j].first == position){
            cur_change += events[j].second;
            j++;
        }

        cur_cost += cur_change;
        ans = min(ans,cur_cost);
        Previousposition = position;
        i = j;
    }

    cout<<ans;

    return 0;
}
