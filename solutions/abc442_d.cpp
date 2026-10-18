#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
ll a[N];
ll tr[N<<2];

void pushup(int u){
    tr[u] = tr[u<<1]+tr[u<<1|1];
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
        tr[u] = val;
        return;
    }

    int mid = (l+r)>>1;
    
    if(pos <= mid)
        modify(u<<1,l,mid,pos,val);
    else
        modify(u<<1|1,mid+1,r,pos,val);

    pushup(u);
}

ll getsum(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tr[u];
    }

    ll res = 0;
    int mid = (l+r)>>1;
    if(mid >= ql)
        res += getsum(u<<1,l,mid,ql,qr);
    if(mid < qr)
        res += getsum(u<<1|1,mid+1,r,ql,qr);

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    build(1,1,n);

    for(int i=0; i<q; i++){
        int op; cin>>op;
        if(op == 1){
            int x; cin>>x;
            modify(1,1,n,x,a[x+1]);
            modify(1,1,n,x+1,a[x]);
            swap(a[x],a[x+1]);
        }else if(op == 2){
            int l,r; cin>>l>>r;
            cout<<getsum(1,1,n,l,r)<<'\n';
        }
    }
}