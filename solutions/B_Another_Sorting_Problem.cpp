#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll mx=0;
    for(int i=0 ; i<n-1 ; i++)
    {
        ll dif=a[i]-a[i+1];
        mx=max(mx,dif);
    }

    for(int i=0 ; i<n-1 ; i++)
    {
        if(a[i+1]<a[i]) a[i+1]+=mx;
    }

    bool pp=1;
    for(int i=0 ; i<n-1 ; i++)
    {
        if(a[i+1]<a[i]){
            pp=0;
            break;
        }
    }

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}