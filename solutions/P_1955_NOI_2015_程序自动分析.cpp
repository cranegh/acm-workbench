#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int fa[N];

int root(int x){
    if(fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

void merge(int x, int y){
    if(root(x) != root(y)) fa[root(x)] = root(y);
}

vector<ll> x;

struct restriction{
    ll i,j;
    int e;
};

int getidx(ll q){
    return lower_bound(x.begin(),x.end(),q)-x.begin();
}

void solve(){
    int n; cin>>n;

    vector<restriction> v(n);
    x.clear();

    for(int ii=0 ; ii<n ; ii++){
        cin>>v[ii].i>>v[ii].j>>v[ii].e;
        x.push_back(v[ii].i);
        x.push_back(v[ii].j);
    }

    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());

    int m = x.size();
    for(int i=0 ; i<m ; i++) fa[i] = i;

    for(int ii=0 ; ii<n ; ii++){
        if(v[ii].e == 1){
            int x = getidx(v[ii].i);
            int y = getidx(v[ii].j);
            merge(x,y);
        }
    }

    bool ok = true;
    for(int ii=0 ; ii<n ; ii++){
        if(v[ii].e == 0){
            int x = getidx(v[ii].i);
            int y = getidx(v[ii].j);
            if(root(x) == root(y)){
                ok = false;
                break;
            }
        }
    }

    if(ok) cout<<"YES\n";
    else cout<<"NO\n";


}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}