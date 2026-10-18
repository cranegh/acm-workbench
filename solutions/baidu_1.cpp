#include<bits/stdc++.h> 

using namespace std;
using ll = long long;

struct monster{
    ll a,b;
    bool operator < (const monster& u) const
    {
        if(a==u.a) return b>u.b;
        else return a<u.a;
    }
};

void solve()
{
    int n,k; ll s;
    cin>>n>>k>>s;
    vector<monster> m(n);

    for(int i=0 ; i<n ; i++) cin>>m[i].a>>m[i].b;
    sort(m.begin(),m.end());

    int cnt = 0;
    ll ans = s;
    for(int i=0 ; i<n ; i++){
        while(m[i].a>ans && cnt<k){
            cnt++;
            ans*=2;
        } 
        if(m[i].a<=ans) ans += m[i].b;
    }
    while(cnt<k){
        cnt++;
        ans*=2;
    }

    cout<<ans<<'\n';
}

int main( )
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}