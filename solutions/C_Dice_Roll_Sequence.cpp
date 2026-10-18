#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    ll ans=0;

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];

    for(int i=1 ; i<n ; i++){
        int last=v[i-1];
        int cur=v[i];

        if(last+cur==7 || last==cur){
            ans++;
            i++;
        }
    }

    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}