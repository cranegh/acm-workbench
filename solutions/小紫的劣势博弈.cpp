#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];

    sort(v.begin(),v.end());

    ll x=0;
    bool red=1;
    for(int i=0 ; i<n ; i++){
        if(red) x+=v[i];
        else x-=v[i];

        red=1-red;
    }

    cout<<x;

    return 0;
}