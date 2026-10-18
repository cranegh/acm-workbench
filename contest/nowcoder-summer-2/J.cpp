#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 200005;
int prefree[N];
int prer[N];
ll init[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    
    int n; cin>>n;
    string s; cin>>s;
    
    init[0] = 1;
    for(int i=1 ; i<=s.size() ; i++) init[i] = (init[i-1]*2)%MOD;

    for(int i=0 ; i<n ; i++){
        if(s[i]=='2') prefree[i+1] = 1;
        if(s[i]=='0') prer[i+1] = 1;
    }

    for(int i=1 ; i<=n ; i++){
        prefree[i] += prefree[i-1];
        prer[i] += prer[i-1];
    }

    int q; cin>>q;
    for(int i=0 ; i<q ; i++){
        int l,r; cin>>l>>r;
        int k = prefree[r] - prefree[l-1];
        ll ans = 0;
        if(k==0){
            int cntr = prer[r] - prer[l-1];
            if(cntr%2) ans = 0;
            else ans = 1;
        }else{
            ans = init[k-1];
        }
        cout<<ans<<'\n';
    }

    return 0;
} 