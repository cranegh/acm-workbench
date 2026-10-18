#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
ll p[N], tr[N<<2];

void pushup(int u){
    tr[u] = max(tr[u<<1],tr[u<<1|1]);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = p[l];
        return;
    }

    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

ll query(int u, int l, int r, int ql, int qr){
    if(ql<=l && r<=qr){
        return tr[u];
    }

    ll res = 0;
    int mid = (l+r)>>1;
    if(ql <= mid)
        res = max(res,query(u<<1,l,mid,ql,qr));
    if(qr > mid)
        res = max(res,query(u<<1|1,mid+1,r,ql,qr));

    return res;
}

void modify(int u, int l, int r, int pos, ll val){
    if(l == r){
        p[l] = val; 
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

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>p[i];
    build(1,1,n);

    for(int i=0; i<m; i++){
        char c; cin>>c;
        if(c == 'Q'){
            int a,b; cin>>a>>b;
            cout<<query(1,1,n,a,b)<<'\n';
        }
        else if(c == 'U'){
            int a; ll b; cin>>a>>b;
            if(p[a] < b) modify(1,1,n,a,b);
        }
    }

}