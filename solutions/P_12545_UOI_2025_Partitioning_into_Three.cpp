#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<unordered_map>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> v(2*n+2);

    for(int i=1 ; i<=n ; i++) cin>>v[i];
    for(int i=1 ; i<=n ; i++) v[i+n]=v[i];

    vector<ll> pre(2*n+2);
    for(int i=1 ; i<=2*n ; i++) pre[i]+=pre[i-1]+v[i];

    ll s=pre[n]/3;

    vector<int> best_cuts = {1, 2, 3};
    ll diff=inf;

    for(int i=1 ; i<=n ; i++){
        int x=i;
        ll target = pre[x-1]+s;

        int y=lower_bound(pre.begin()+x,pre.end(),target)-pre.begin()+1;

        for(int iy=y-2 ; iy<=y+2 ; iy++){
            if (iy <= x || iy > x + n - 2) continue;
            ll target = pre[iy-1]+(pre[n]-(pre[iy-1]-pre[x-1]))/2;

            int z=lower_bound(pre.begin()+iy,pre.end(),target)-pre.begin()+1;

            for(int iz=z-2 ; iz<=z+2 ; iz++){
                if (iz <= iy || iz > x + n - 1) continue;

                ll s1=pre[iy-1]-pre[x-1];
                ll s2=pre[iz-1]-pre[iy-1];
                ll s3=pre[n+x-1]-pre[iz-1];

                ll mx=max({s1,s2,s3});
                ll mn=min({s1,s2,s3});

                if(mx-mn<diff){
                    diff=mx-mn;
                    best_cuts={x,iy,iz};
                }
            }
        }
    } 

    vector<int> ans(3);
    for(int i=0 ; i<3 ; i++){
        ans[i]=(best_cuts[i]-1)%n+1;
    }

    cout<<diff<<'\n';

    sort(ans.begin(),ans.end());

    for(int i=0 ; i<3 ; i++) cout<<ans[i]<<' ';


    return 0;
}