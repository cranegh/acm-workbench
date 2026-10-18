#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500005;

ll pre[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,c,p,q; cin>>n>>c>>p>>q;
    string s; cin>>s;

    for(int i=0 ; i<n ; i++){
        if(s[i]=='Y') pre[i+1] = pre[i] + q-p;
        else if(s[i]=='N') pre[i+1] = pre[i] + -p;
    }

    int t = 0;
    ll ans = 0;
    ll mn = LLONG_MAX;
    for(int i=1 ; i<=n ; i++){
        if(i-t >= c){
            mn = min(mn,pre[i-c]);
        }

        if(pre[i]>=mn){
            ans++;
            t = i;
            mn = LLONG_MAX;
        }
    }

    cout<<ans;

    return 0;
} 