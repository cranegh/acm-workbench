#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    ll t=1ll*n*(n+1)*m*(m+1)/4;
    int a=min(m,n);
    ll z=0;
    for (int i=1 ; i<=a ; i++){
        z+=(m+1ll-i)*(n+1-i);
    }
    ll c=t-z;
    cout<<z<<' '<<c;

    return 0;
}