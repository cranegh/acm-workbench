#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(10);

    int n,m; ll k;
    cin>>n>>m>>k;

    double ans = 1.0*(2*n+k-1)*m*k/(2*(n+k));

    cout<<ans;

    return 0;
}