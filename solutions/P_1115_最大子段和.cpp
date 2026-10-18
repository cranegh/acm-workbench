#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 20000+5;
int pre[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll mn = 0;
    ll ans = -INF;
    ll cur = 0;
    for(int i=0 ; i<n ; i++){
        cur += a[i];
        ans = max(ans,cur-mn);
        mn = min(mn,cur);
    }

    cout<<ans;


    return 0;
}