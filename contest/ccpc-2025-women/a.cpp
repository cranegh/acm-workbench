#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,s,t; cin>>n>>s>>t;
    int x;
    if(t>s){
        if(t-s < s+n-t) x = 1;
        else x = 2;
    }else{
        if(s-t > t+n-s) x = 1;
        else x = 2;
    }

    cout<<x;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}