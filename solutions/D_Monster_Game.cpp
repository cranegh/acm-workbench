#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long; 

void solve()
{
    int n; cin>>n;

    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    vector<ll> b(n+1);
    for(int i=1 ; i<=n ; i++) cin>>b[i];

    vector<ll> pre(n+1);
    for(int i=1 ; i<=n ; i++) pre[i]=pre[i-1]+b[i];

    ll ans=0;

    for(int i=0 ; i<n ; i++){
        ll x=a[i];
        int cnt=i+1;
        
        int l=0,r=n+1;
        while(l+1!=r){
            int mid=(l+r)/2;
            if(pre[mid]>cnt) r=mid;
            else l=mid;
        }

        ans=max(ans,l*x);
    }

    cout<<ans<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}