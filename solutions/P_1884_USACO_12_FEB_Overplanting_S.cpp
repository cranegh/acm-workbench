#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2005;
ll diff[N][N];

struct rectangle{
    ll x1,y1;
    ll x2,y2;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<rectangle> v(n);
    vector<ll> xs,ys;

    for(int i=0 ; i<n ; i++){
        int xl,yl,xr,yr; cin>>xl>>yl>>xr>>yr;
        v[i].x1 = min(xl,xr);
        v[i].x2 = max(xl,xr);
        v[i].y1 = min(yl,yr);
        v[i].y2 = max(yl,yr);

        xs.push_back(v[i].x1);
        xs.push_back(v[i].x2);
        ys.push_back(v[i].y1);
        ys.push_back(v[i].y2);
    }

    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());

    sort(ys.begin(),ys.end());
    ys.erase(unique(ys.begin(),ys.end()),ys.end());

    for(const auto &cur : v){
        int l = lower_bound(xs.begin(),xs.end(),cur.x1)-xs.begin();
        int r = lower_bound(xs.begin(),xs.end(),cur.x2)-xs.begin();
        int b = lower_bound(ys.begin(),ys.end(),cur.y1)-ys.begin();
        int t = lower_bound(ys.begin(),ys.end(),cur.y2)-ys.begin();

        diff[l][b]++;
        diff[r][b]--;
        diff[l][t]--;
        diff[r][t]++;
    }

    int nx = xs.size();
    int ny = ys.size();
    ll ans = 0;

    for(int i=0 ; i<nx ; i++){
        for(int j=0 ; j<ny ; j++){
            if(i>0) diff[i][j] += diff[i-1][j];
            if(j>0) diff[i][j] += diff[i][j-1];
            if(i>0 && j>0) diff[i][j] -= diff[i-1][j-1];

            if(i+1<nx && j+1<ny && diff[i][j]){
                    ll wid = xs[i+1] - xs[i]; 
                    ll hei = ys[j+1] - ys[j];
                    ans += wid*hei;
            }
        }
    }
    
    cout<<ans;

    return 0;
}
