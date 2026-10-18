#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll d[] = {1,10,100,1000,10000,100000,1000000};

void solve()
{
    string x; cin>>x;
    int len = x.length();

    ll ans = 0;
    if(x[0]=='1'){
        for(int i=1 ; i<len ; i++) ans += (x[i]-'0')*d[len-i-1];
        ans += d[len-2];
        ans += 1;
    }else{
            ans += d[len-1];
            for(int i=1 ; i<len ; i++) ans += (x[i]-'0')*d[len-i-1];
            ans += 1;
    }

    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}