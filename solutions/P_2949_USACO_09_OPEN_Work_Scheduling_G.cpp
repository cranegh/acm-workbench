#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector< pair<ll,ll> > job(n);
    for(int i=0 ; i<n ; i++){
        ll d,p; cin>>d>>p;
        job[i]={d,p};
    }
    sort(job.begin(),job.end());

    ll time = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pp;
    ll tt = 0;

    for(int i=0 ; i<n ; i++){
        if(job[i].first>time){
            time++;
            pp.push(job[i].second);
            tt += job[i].second;
        }else if(!pp.empty() && pp.top()<job[i].second){
            tt -= pp.top();
            tt += job[i].second;
            pp.pop();
            pp.push(job[i].second);
        }
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