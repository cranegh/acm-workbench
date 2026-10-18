#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    vector<int> ans;
    ll k,x; cin>>k>>x;
    ll goal = (1ll*1<<k);

    ll c = x;
    ll a = goal*2 - c;

    while(a!=c){
        if(c>goal){
            c-=a;
            a*=2;
            ans.push_back(2);
        }else{
            a-=c;
            c*=2;
            ans.push_back(1);
        }
    }

    cout<<ans.size()<<'\n';
    for(int i=ans.size()-1 ; i>=0 ; i--) cout<<ans[i]<<" ";
    cout<<'\n';
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}