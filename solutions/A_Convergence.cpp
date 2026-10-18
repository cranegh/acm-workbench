#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll n; cin>>n;
    map<ll,int> mp;
    vector<ll> pp(n);
    set<ll> st;
    for(int i=0 ; i<n ; i++) cin>>pp[i];
    for(int i=0 ; i<n ; i++) st.insert(pp[i]);
    for(int i=0 ; i<n ; i++)
    {
        ll pos = pp[i];
        if(mp.count(pos)) mp[pos]++;
        else mp[pos]=1;
    }

    ll fro = 0;
    ll mn=n;
    for(auto it = st.begin() ; it!=st.end() ; it++)
    {
        ll bak = n - fro - mp[*it];
        mn = min(mn,max(fro,bak));
        fro+=mp[*it];
    }

    cout<<mn<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}