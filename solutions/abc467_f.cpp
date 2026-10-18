#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N],tr[N<<2],lzy[N<<2];

void pushup(int u){
    tr[u] = tr[u<<1] + tr[u<<1|1];
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = a[l];
        return;
    }

    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

void apply(int u, int l, int r, ll val){
    tr[u] += (r-l+1)*val;
    lzy[u] += val;
}

void pushdown(int u, int l, int r){
    if(lzy[u] == 0){
        return;
    }
    
    int mid = (l+r)>>1;
    apply(u<<1,l,mid,lzy[u]);
    apply(u<<1|1,mid+1,r,lzy[u]);

    lzy[u] = 0;
}

void modify(int u, int l, int r, int ql, int qr, ll val){
    if(ql <= l && r <= qr){
        apply(u,l,r,val);
        return;
    }

    pushdown(u,l,r);
    int mid = (l+r)>>1;
    if(mid >= ql)
        modify(u<<1,l,mid,ql,qr,val);
    if(mid < qr)
        modify(u<<1|1,mid+1,r,ql,qr,val);

    pushup(u);
}

ll query(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tr[u];
    }

    pushdown(u,l,r);
    int mid = (l+r)>>1;

    ll res = 0;
    if(mid >= ql)
        res += query(u<<1,l,mid,ql,qr);
    if(mid < qr)
        res += query(u<<1|1,mid+1,r,ql,qr);

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    build(1,1,n);

    for(int i=0; i<m; i++){
        int op; cin>>op;
        if(op == 1){
            int ql,qr; cin>>ql>>qr;
            ll k; cin>>k;
            modify(1,1,n,ql,qr,k);
        }else{
            int ql,qr; cin>>ql>>qr;
            cout<<query(1,1,n,ql,qr)<<'\n';
        }
    }

}