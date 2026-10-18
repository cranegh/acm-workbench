#include<bits/stdc++.h>

using namespace std;
using ll = long long; 

const int N = 1000000+5;
int ans[N];
ll pw[61];

void solve()
{
    int x; ll k; cin>>x>>k;
    
    int n = 1;
    ans[n] = 0;

    int r = x;

    while(r>0){
        ans[n]++;
        r--;
        if(k==1) break;
        if(r>60 || k<=pw[r]){
            n++;
            ans[n] = 0;
            k--;
        }else{
            k -= pw[r];
        }
    }
    for(int i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=0 ; i<61 ; i++) pw[i] = 1ll<<i;

    int T; cin>>T;
    while(T--) solve();

}