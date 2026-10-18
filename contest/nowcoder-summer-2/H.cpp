#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
ll d[N];
ll bfit[N];

bitset<N> die;

ll f(int x){
    ll res = 1ll*x*(x-1)/2;
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> b(n),e(n);
    vector<ll> X;

    for(int i=0 ; i<n ; i++) cin>>b[i]>>e[i];
    for(int i=0 ; i<n ; i++){
        X.push_back(b[i]);
        X.push_back(e[i]);
    }

    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());

    int nx = X.size();
    ll ans = 0;
    
    for(int i=0 ; i<n ; i++){
        int x = lower_bound(X.begin(),X.end(),b[i])-X.begin();
        d[x]++;
    }
    
    for(int i=0 ; i<n ; i++){
        int x = lower_bound(X.begin(),X.end(),e[i])-X.begin();
        d[x]--;
        die[x] = true;
    }

    
    ll cur = 0;
    for(int i=1 ; i<=nx ; i++){
        cur += d[i];
        bfit[i] += (cur-1);      
    }

    for(int i=1 ; i<=n ; i++){
        if(die[i] && (cur-1)>=2 ) ans += f(cur-1);
        cur += d[i];
    }

    cout<<ans;

    return 0;
} 