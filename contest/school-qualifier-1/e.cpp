#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll tt = 0;
    for(ll i=1 ; i<=n ; i++) tt += i*(n-i+1);

    int top = 0;
    vector<ll> st(n+1);
    ll rdc = 0;
    
    for(ll i=n-1 ; i>=0 ; i--){
        while(top>0 && a[st[top]]==a[i]+1){
            ll j = st[top];
            rdc += (i+1)*(n-j);

            top--;
        }

        st[++top] = i; 
    }

    ll ans = tt - rdc;
    cout<<ans<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int T; cin>>T;
    while(T--) solve();

    return 0;
}