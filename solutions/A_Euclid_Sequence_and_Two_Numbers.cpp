#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll>b(n);
    for(int i=0 ; i<n ; i++) cin>>b[i];

    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    bool pp = true;
    ll x = b[0]; ll y = b[1];
    if(n==2){
        pp = true;
    }else{
        for(int i=0 ; i<=n-3 ; i++){
            if(b[i+2]!=b[i]%b[i+1]){
                pp = false;
                break;
            }
        }
    }

    if(!pp) cout<<-1<<'\n';
    else cout<<x<<" "<<y<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}