#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505;
ll a[N][N], sum[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    int q; cin>>q;

    ll ans = 0;
    for(int i=0; i<q; i++){
        int r,c;
        ll v;
        cin>>r>>c>>v;

        ll delta = v - a[r][c];
        a[r][c] = v;

        int r1 = max(r-k+1,1);
        int c1 = max(c-k+1,1);

        int r2 = min(n-k+1,r);
        int c2 = min(n-k+1,c);

        for(int R=r1; R<=r2; R++){
            for(int C=c1; C<=c2; C++){
                sum[R][C] += delta;
            }
        }
        
        for(int R=r1; R<=r2; R++){
            for(int C=c1; C<=c2; C++){
                ans = max(ans,sum[R][C]);
            }
        }

        cout<<ans<<'\n';

    }

    return 0;

}