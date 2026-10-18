#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll qpow(ll a, ll n)
{
    ll res=1;
    while(n>=1){
        if(n%2==1) res*=a;
        a*=a;
        n/=2;
    }
    return res;
}

void solve()
{
    int m; cin>>m;
    vector<pair<int,int>> a;
    int mm=0;
    for(int i=0 ; i<m ; i++){
        int u; char v1;
        cin>>u>>v1;
        int v;
        if('0'<=v1 && v1<='9') v=v1-'0';
        else if(v1=='A') v=10;

        a.push_back({u,v});
        mm+=u;
    }

    mm--;

    ll sum=0;
    for(auto &[u,v] : a){
        for(int i=0 ; i<u ; i++){
            sum+=v*qpow(11,mm);
            //cout<<sum<<" "<<mm<<'\n';
            mm--;
        }
    }

    //cout<<mm<<"\n";
    //cout<<sum<<'\n';

    if(sum%5==0) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}