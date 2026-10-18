#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
ll dx[N],dy[N],dz[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; ll a,b,c; cin>>n>>a>>b>>c;
    vector<ll> xb(n),yb(n),zb(n);
    vector<ll> xe(n),ye(n),ze(n);

    vector<ll> Xx,Xy,Xz;

    for(int i=0; i<n; i++){
        ll a1,b1,c1,a2,b2,c2;
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        if(a1>a2)swap(a1,a2);
        if(b1>b2)swap(b1,b2);
        if(c1>c2)swap(c1,c2);
        xb[i] = a1,xe[i] = a2;
        yb[i] = b1,ye[i] = b2;
        zb[i] = c1,ze[i] = c2;
        Xx.push_back(a1);
        Xx.push_back(a2);
        Xy.push_back(b1);
        Xy.push_back(b2);
        Xz.push_back(c1);
        Xz.push_back(c2);
    }

    sort(Xx.begin(),Xx.end());
    sort(Xy.begin(),Xy.end());
    sort(Xz.begin(),Xz.end());

    Xx.erase(unique(Xx.begin(),Xx.end()),Xx.end());
    Xy.erase(unique(Xy.begin(),Xy.end()),Xy.end());
    Xz.erase(unique(Xz.begin(),Xz.end()),Xz.end());

    int nx = Xx.size();
    int ny = Xy.size();
    int nz = Xz.size();

    for(int i=0 ; i<n ; i++){
        int x = lower_bound(Xx.begin(),Xx.end(),xb[i])-Xx.begin();
        int y = lower_bound(Xy.begin(),Xy.end(),yb[i])-Xy.begin();
        int z = lower_bound(Xz.begin(),Xz.end(),zb[i])-Xz.begin();

        dx[x]++;
        dy[y]++;
        dz[z]++;
    }
    
    for(int i=0 ; i<n ; i++){
        int x = lower_bound(Xx.begin(),Xx.end(),xe[i])-Xx.begin();
        int y = lower_bound(Xy.begin(),Xy.end(),ye[i])-Xy.begin();
        int z = lower_bound(Xz.begin(),Xz.end(),ze[i])-Xz.begin();

        if(x+1<=nx) dx[x+1]--;
        if(y+1<=ny) dy[y+1]--;
        if(z+1<=nz) dz[z+1]--;
    }

    ll mx=0;

    for(int i=1; i<=nx; i++){
        dx[i] += dx[i-1];
        mx = max(mx,dx[i]);
    }

    for(int i=1; i<=ny; i++){
        dy[i] += dy[i-1];
        mx = max(mx,dy[i]);
    }

    for(int i=1; i<=nz; i++){
        dz[i] += dz[i-1];
        mx = max(mx,dz[i]);
    }

    cout<<mx;

    return 0;
} 