#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<bitset>
#include<queue>

using namespace std;
using ll = long long;

const int N = 2e5+9;

ll ans=0;

void f(ll x){
    while(x!=1){
        if(x%2==0) x/=2;
        else x=x*3+1;

        ans=max(ans,x);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n; cin>>n;

    for(ll i=1 ; i<=n ; i++) f(i);

    cout<<ans;

    return 0;
}