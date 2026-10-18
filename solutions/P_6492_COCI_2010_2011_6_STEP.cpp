#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
    int len;

    int lv,rv;
    int pre,suf;

    int ans;
};

const int N = 200005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
Node tr[N<<2];

Node mergeNode(Node l, Node r){
    Node res;

    res.len = l.len + r.len;

    res.lv = l.lv;
    res.rv = r.rv;

    res.pre = l.pre;
    res.suf = r.suf;

    res.ans = max(l.ans,r.ans);

    if(l.rv != r.lv){
        res.ans = max(res.ans,l.suf+r.pre);

        if(l.pre == l.len)
            res.pre = l.len + r.pre;

        if(r.suf == r.len)
            res.suf = r.len + l.suf;
    }

    return res;
}

void pushup(int u){
    tr[u] = mergeNode(tr[u<<1],tr[u<<1|1]);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {1,0,0,1,1,1};
        return;
    }

    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

void modify(int u, int l, int r, int pos){
    if(l == r){
        tr[u].lv ^= 1;
        tr[u].rv ^= 1;
        return;
    }

    int mid = (l+r)>>1;
    if(pos <= mid)
        modify(u<<1,l,mid,pos);
    else
        modify(u<<1|1,mid+1,r,pos);
    
    pushup(u);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,q; cin>>n>>q;
    build(1,1,n);

    for(int i=0; i<q; i++){
        int x; cin>>x;
        modify(1,1,n,x);
        cout<<tr[1].ans<<'\n';
    }

}