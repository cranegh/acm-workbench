#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
    int mn, mnpos;
    int mx, mxpos;
};

const int N = 200005;
int p[N];
Node tr[N<<2];

int n,m;

Node mergeNode(Node lc, Node rc){
    Node res;

    if(lc.mn < rc.mn){
        res.mn = lc.mn;
        res.mnpos = lc.mnpos;
    }else{
        res.mn = rc.mn;
        res.mnpos = rc.mnpos;
    }
    
    if(lc.mx > rc.mx){
        res.mx = lc.mx;
        res.mxpos = lc.mxpos;
    }else{
        res.mx = rc.mx;
        res.mxpos = rc.mxpos;
    }

    return res;
}

void pushup(int u){
    tr[u] = mergeNode(tr[u<<1],tr[u<<1|1]);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {p[l],l,p[r],r};
        return;
    }

    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

void update(int u, int l, int r, int pos, int val){
    if(l == r){
        tr[u] = {val,pos,val,pos};
        return;
    }

    int mid = (l+r)>>1;

    if(pos <= mid)
        update(u<<1,l,mid,pos,val);
    else
        update(u<<1|1,mid+1,r,pos,val);

    pushup(u);
}

Node query(int u, int l, int r, int ql, int qr){
    if(ql<=l && r<=qr){
        return tr[u];
    }

    int mid = (l+r)>>1;
    Node res = {n+2,0,0,0};

    if(mid >= ql)
        res = mergeNode(res,query(u<<1,l,mid,ql,qr));
    if(qr > mid)
        res = mergeNode(res,query(u<<1|1,mid+1,r,ql,qr));

    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>p[i];

    build(1,1,n);

    for(int i=0; i<m; i++){
        int l,r; cin>>l>>r;
        Node cur = query(1,1,n,l,r);
        
        int x = cur.mnpos, y = cur.mxpos;
        swap(p[x],p[y]);

        update(1,1,n,x,p[x]);
        update(1,1,n,y,p[y]);
    }

    for(int i=1; i<=n; i++) cout<<p[i]<<" ";

    return 0;
}