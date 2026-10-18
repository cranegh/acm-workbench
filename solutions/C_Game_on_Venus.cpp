#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 3e5+9;
ll prefix[N],a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=3*n ; i++) cin>>a[i];

    sort(a+1,a+1+3*n);
    for(int i=1 ; i<=3*n ; i++) prefix[i]=prefix[i-1]+a[i];
    ll ans2=3*prefix[n];
    ll ans1=prefix[3*n]-prefix[n];

    cout<<ans1<<' '<<ans2;

    return 0;
}