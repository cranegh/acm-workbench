#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++) cin>>v[i];

    sort(v.begin(),v.end());

    int ans = max(v[0],v[1]-v[0]);

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}



