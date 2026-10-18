#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1000000000000000000;

void solve()
{   
    ll l = 1, r = N+1;
    while(l+1!=r){
        ll mid = (l+r)/2;
        cout<<"X "<<mid<<endl;
        ll a,b; cin>>a>>b;
        if(a==0){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<"N "<<l<<endl;
    string ss; cin>>ss;
}

int main()
{
    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}