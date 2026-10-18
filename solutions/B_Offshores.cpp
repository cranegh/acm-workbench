#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n,x,y; cin>>n>>x>>y;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    int last_idx=0;
    ll best_remin=a[0]%x+a[0]/x*(x-y);
    for(int i=0 ; i<n ; i++){
        int temp=a[i]%x;
        int k = a[i]/x;
        temp+=k*(x-y);

        if(temp>best_remin){
            best_remin=temp;
            last_idx=i;
        }
    }

    ll ans=a[last_idx];

    for(int i=0 ; i<n ; i++){
        if(i==last_idx) continue;

        int k = a[i]/x;
        ans+=k*y;
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