#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500005;
ll a[N], tr[N<<2];

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

void modify(int u, int l, int r, int pos, ll val){
    if(l == r){
        tr[u] += val;
        return;
    }

    int mid = (l+r)>>1;
    if(pos <= mid)
        modify(u<<1,l,mid,pos,val);
    else
        modify(u<<1|1,mid+1,r,pos,val);

    pushup(u);
}

ll query(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tr[u];
    }

    ll res = 0;
    int mid = (l+r)>>1;
    if(mid >= ql)
        res += query(u<<1,l,mid,ql,qr);
    if(qr > mid)
        res += query(u<<1|1,mid+1,r,ql,qr);
    
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    build(1,1,n);

    for(int i=0; i<m; i++){
        int op; cin>>op;
        if(op == 1){
            int x; ll k;
            cin>>x>>k;
            modify(1,1,n,x,k);
        }else{
            int x,y; cin>>x>>y;
            cout<<query(1,1,n,x,y)<<'\n';
        }
    }


}