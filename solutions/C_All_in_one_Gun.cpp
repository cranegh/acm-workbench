#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    ll n,h,k; cin>>n>>h>>k;
    vector<ll> v(n+1);

    for(int i=1 ; i<=n ; i++){
        cin>>v[i];
    }

    ll sum=0;
    for(int i=1 ; i<=n ; i++) sum+=v[i];

    vector<ll> aft_max(n+1);

    ll cur_max=v[n];
    for(int i=n ; i>=1 ; i--){
        if(v[i]>cur_max) cur_max=v[i];
        int cur=n+1-i;
        aft_max[cur]=cur_max;
    }

    ll m = h/sum;
    ll t=0;
    if(h%sum==0){
        t+=(m-1)*k+m*n;
    }else if(h%sum!=0){
        t+=m*k+m*n;

        ll remin = h-sum*m;
        ll cur_sum=0;
        ll min_v=v[1];

        ll x=0;
        for(int i=1 ; i<=n ; i++){
            cur_sum+=v[i];
            if(v[i]<min_v) min_v=v[i];
            ll temp=max(cur_sum,cur_sum-min_v+aft_max[n-i]);

            if(temp>=remin){
                x=i;
                break;
            }
        }
        t+=x;
    }

    cout<<t<<'\n';

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}