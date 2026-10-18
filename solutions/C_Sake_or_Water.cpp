#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,k,x; cin>>n>>k>>x;
    vector<ll> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int num_w=n-k;
    int num_nd=0;
    ll sum_sake=0;

    for(int i=n-k ; i<n ; i++){
        sum_sake+=a[i];
        if(sum_sake>=x){
            num_nd=i-n+k+1;
            break;
        }else if(i==n-1 && sum_sake<x){
            cout<<-1;
            return 0;
        }
    }

    int ans=num_w+num_nd;

    cout<<ans;

    return 0;
}