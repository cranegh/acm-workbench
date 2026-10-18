#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<pair<ll,ll>> v(n);

    for(int i=0 ; i<n ; i++) cin>>v[i].first>>v[i].second;

    sort(v.begin(),v.end());

    ll ans = 0;
    ll last_left = v[0].first;
    ll last_right = v[0].second;

    for(int i=1 ; i<n ; i++){
        if(v[i].first>last_right){
            ans += last_right-last_left;
            last_left = v[i].first;
            last_right = v[i].second;
        }else{
            last_right = max(last_right,v[i].second);
        }
    }
    
    ans += last_right-last_left;

    cout<<ans;

    return 0;
}