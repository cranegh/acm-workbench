#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

const int MOD = 998244353;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int q; cin>>q;
    while(q--){
        ll tt=1;
        string s; cin>>s;

        vector<ll> dp(128,0);

        for(int c : s){
            ll pre_tt=tt;

            tt=(tt+pre_tt-dp[c]+MOD)%MOD;

            dp[c]=pre_tt;
        }

        cout<<tt<<'\n';
    }


    return 0;
}