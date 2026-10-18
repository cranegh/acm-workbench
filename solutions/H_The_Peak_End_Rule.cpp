#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    vector<pair<ll,int>> v(n);
    for(int i=0 ; i<n ; i++){
        v[i]={a[i],i};
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    
    vector<int> flag;
    int limit = 2*k-1;
    for(int i=0; i<n; i++) {
        if(v[i].second != n-1){
            if(flag.empty() || v[i].first>0)
            flag.push_back(v[i].second);
            if(flag.size() == limit) break;
        }
    }
    
    sort(flag.begin(),flag.end());

    ll ans = 0;
    vector<int> g(n,1);

    ans += a[n-1];

    if(!flag.empty()){
        int cur = flag.back();
        flag.pop_back();
        ans += a[cur];
    }

    int group = 2;
    for(int i=flag.size()-1 ; i>=0 ; i-=2)
    {
        int cure = flag[i];
        g[cure] = group;
        ans += a[cure];
        
        if(i-1>=0){
            int curp = flag[i-1];
            g[curp] = group;
            ans += a[curp];
        }

        group++;
    }

    cout<<ans<<'\n';
    for(int i=0 ; i<n ; i++) cout<<g[i]<<" ";

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}