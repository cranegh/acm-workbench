#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 310;
int h[N];

int main(){
    int n; cin>>n;

    for(int i=1 ; i<=n ; i++) cin>>h[i];
    sort(h+1,h+1+n);
    h[0]=0;

    ll ans=(h[n]-h[0])*(h[n]-h[0]);
    for(int i=1 ; i<=n ; i++){
        ans+=(h[i]-h[n-i+1])*(h[i]-h[n-i+1]);
        ans+=(h[i]-h[n-i])*(h[i]-h[n-i]);
    }

    cout<<ans/2;


}