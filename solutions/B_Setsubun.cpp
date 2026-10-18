#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;
using ll =long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,k; cin>>n>>k;
    ll sum=0;
    ll ans=0;
    for(int i=0 ; sum<k ; i++){
        sum+=(i+n);
        ans=i;
    }

    cout<<ans;


    return 0;
}