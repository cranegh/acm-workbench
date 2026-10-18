#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string sa; cin>>sa; vector<int> a(n); for(int i=0 ; i<n ; i++) a[i] = sa[i]-'0';
    string sb; cin>>sb; vector<int> b(n); for(int i=0 ; i<n ; i++) b[i] = sb[i]-'0';

    bool ans = false;

    int acnt1 = 0;
    int acnt0 = 0;
    int bcnt1 = 0;
    int bcnt0 = 0;

    for(int i=0 ; i<n ; i++){
        if(a[i]==1){
            if(i%2) acnt0++;
            else acnt1++;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(b[i]==1){
            if(i%2) bcnt0++;
            else bcnt1++;
        }
    }

    if(acnt0==bcnt0 && acnt1==bcnt1) ans = true;
    
    if(ans) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();

    return 0;
}