#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int w[N];
int v[N];
int l[N],r[N];

int ww[N];

int n,m; ll s; 

ll cal(int W){
    vector<int> cnt(n+1,0);
    vector<ll> sumv(n+1,0);
    for(int i=1 ; i<=n ; i++){
        cnt[i] = cnt[i-1] + (w[i]>=W);
    }
    
    for(int i=1 ; i<=n ; i++){
        sumv[i] = sumv[i-1] + (w[i]>=W)*v[i];
    }
    
    ll res = 0;
    for(int i=1 ; i<=m ; i++){
        int curl = l[i];
        int curr = r[i];
    
        int cur_cnt = cnt[curr]-cnt[curl-1];
        ll cur_sumv = sumv[curr]-sumv[curl-1];
    
        res += cur_cnt*cur_sumv;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>s;
    for(int i=1 ; i<=n ; i++) cin>>w[i]>>v[i];
    for(int i=1 ; i<=m ; i++) cin>>l[i]>>r[i];

    for(int i=1 ; i<=n ; i++) ww[i] = w[i];
    sort(ww+1,ww+1+n);

    ll right = n+1;
    ll left = 1;
    while(left+1!=right){
        int mid = (left+right)>>1;
        ll W = ww[mid];

        ll res = cal(W);
        
        if(res>=s) left = mid;
        else right = mid;
    }
    
    ll ans1 = cal(ww[left]);
    ll ans2 = ans1;
    if(right!=n+1) ans2 = cal(ww[right]);

    ans1 = abs(ans1-s);
    ans2 = abs(s-ans2);
    
    ll ans = min(ans1,ans2);
    
    cout<<ans;

    return 0;
}