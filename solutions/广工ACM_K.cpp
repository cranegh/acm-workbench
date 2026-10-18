#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
using ll = long long;

const int N = 2e5+9;
ll a[N],d[N],pre[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    multiset<ll> ms;
    int n; cin>>n;
    for(int i=0 ; i<n ; i++) cin>>a[i];

    for(int i=1 ; i<n ; i++) d[i]=a[i]-a[i-1];
    sort(d+1,d+n);

    for(int i=1 ; i<=n ; i++) pre[i]+=pre[i-1]+d[i];

    for(int i=1 ; i<=n ; i++){
        cout<<pre[n-i]<<' ';
    }

    return 0;

}
