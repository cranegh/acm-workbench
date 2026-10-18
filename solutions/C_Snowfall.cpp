#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a2;
    vector<ll> a3;
    vector<ll> a6;
    vector<ll> a;

    for(int i=0 ; i<n ; i++){
        ll tmp; cin>>tmp;
        if(tmp%6==0) a6.push_back(tmp);
        else if(tmp%3==0) a3.push_back(tmp);
        else if(tmp%2==0) a2.push_back(tmp);
        else a.push_back(tmp);
    }

    for(int i=0 ; i<a6.size() ; i++) cout<<a6[i]<<' ';
    for(int i=0 ; i<a2.size() ; i++) cout<<a2[i]<<' ';
    for(int i=0 ; i<a.size() ; i++) cout<<a[i]<<' ';
    for(int i=0 ; i<a3.size() ; i++) cout<<a3[i]<<' ';
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}