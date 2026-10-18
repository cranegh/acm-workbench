#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 8005;
ll a[N];
ll pre[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,s; ll l; cin>>n>>s>>l;
    for(int i=1; i<n; i++) cin>>a[i];

    for(int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];

    int L = s, R = s;
    for(int i=s; i>=1; i--){
        if(pre[s-1] - pre[i-1] <= l){
            L = i;
        }else{
            break;
        }
    }

    int ans = 0;
    for(int i=L; i<=s; i++){
        while(1){
            if(R>n) break;
            ll s1 = 2 * (pre[R-1] - pre[s-1]) + pre[s-1] - pre[i-1];
            ll s2 = pre[R-1] - pre[s-1] + 2 * (pre[s-1] - pre[i-1]);
            ll cur_s = min(s1,s2);
            if(R<=n && cur_s<=l){
                ans = max(ans,R-i+1);
                R++;
            }
            else break;
        }
    }

    cout<<ans;

    return 0;
}