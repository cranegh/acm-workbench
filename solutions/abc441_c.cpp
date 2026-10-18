#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    ll n,k,x; cin>>n>>k>>x;

    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    int water = n-k;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int sake;
    ll cnt=0;
    for(sake=1 ; sake<k+1 ; sake++){
        cnt+=a[n-k-1+sake];
        if(cnt>=x) break;
    }

    if(cnt<x) cout<<-1;
    else cout<<sake+water;
    
    return 0;
}