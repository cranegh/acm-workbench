#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long; 


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,c; cin>>n>>c;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];
    sort(v.begin(),v.end());

    ll ans=0;

    for(int i=0 ; i<n ; i++){
        int b=v[i];
        int a=b+c;
        auto it_lower=lower_bound(v.begin(),v.end(),a);
        auto it_upper=upper_bound(v.begin(),v.end(),a);
        ans+=(it_upper-it_lower);
    }

    cout<<ans;

    return 0;
}