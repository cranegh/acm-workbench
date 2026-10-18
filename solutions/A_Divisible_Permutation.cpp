#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> v;

    for(int i=1 ; i<=n/2 ; i++) v.push_back(n+1-i),v.push_back(i);
    if(n%2==1) v.push_back(n/2+1);
    
    reverse(v.begin(),v.end());
    for(int i : v) cout<<i<<' ';
    cout<<'\n';
 
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}



