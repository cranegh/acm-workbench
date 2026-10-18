#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
ll a[N], d[N], ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    ll mx = 0;
    for(int i=1; i<=n; i++) mx = max(mx,a[i]);

    for(int i=1; i<=n; i++){
        d[1]++;
        d[a[i]+1]--;
    }

    int cur = 0;
    for(int i=1; i<=mx; i++){
        cur += d[i];
        ans[i] = cur;
    }

    int len = 0;
    for(int i=1; ans[i]; i++){
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
        len++;
    }
    
    for(int i=len; i>=1; i--){
        cout<<ans[i];
    }
    
    return 0;
}