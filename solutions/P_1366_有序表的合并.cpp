#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#include<vector>

using namespace std;
using ll = unsigned long long;

void solve()
{
    vector<ll> ans;
    int n,m; cin>>n>>m;
    vector<ll> a(n+1);
    vector<ll> b(m+1);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=m ; i++) cin>>b[i];

    ll sum=0;
    for(int i=1,j=1 ; i<=n ; i++){
        int temp=0;
        while(j<=m && b[j]<a[i]) j++;
        while(j<=m && a[i]==b[j]) j++,temp++;
        sum^=temp;
    }

    cout<<sum<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}