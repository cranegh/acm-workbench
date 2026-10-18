#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    vector<ll> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    ll mx = 0;
    ll sum = 0;
    for(ll xx : x){
        sum += xx;
        if(xx>mx) mx = xx;
    }
    ll ave = (sum+n-1)/n;
    ll st = max(ave,mx);

    ll l = st-1;
    ll r = sum;
    while(l+1!=r){
        ll mid = (l+r)/2;

        int curk = 1;
        ll cur_sum = 0;
        for(int i=0; i<n; i++){
            if(cur_sum+x[i] <= mid){
                cur_sum += x[i];
            }else{
                cur_sum = x[i];
                curk++;
            }
        }
        if(curk <= k) r = mid;
        else l = mid; 
    }
    cout<<r;
    
    return 0;
}