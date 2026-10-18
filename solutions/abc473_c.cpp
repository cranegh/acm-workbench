#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int cnt[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,k; cin>>n>>k;
    int mx = 0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        cnt[a]++;
        mx = max(mx,cnt[a]);
    }

    int ans = 0;
    for(int i=1; i<=k; i++){
        if(cnt[i]+1 >= mx) ans++;
    }

    cout<<ans;

    return 0;
}