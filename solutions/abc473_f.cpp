#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node{
    ll mn;
    ll sum;
};

int n,q;
string s;

const int N = 500005;
Node tr[N<<2];

Node merge(Node l, Node r){
    Node res;
    res.sum = l.sum + r.sum;
    res.mn = min(l.mn,r.mn+l.sum);
    return res;
}

void pushup(int u){
    tr[u] = merge(tr[u<<1],tr[u<<1|1]);
}

void build(int u, int l, int r){
    if(l == r){
        ll cur_mn = 0;
        ll cur_sum = 0;

        if(s[l] == 'A'){
            cur_mn = 1;
            cur_sum = 1;
        }else{
            cur_mn = -1;
            cur_sum = -1;
        }

        tr[u] = {cur_mn,cur_sum};
        return;
    }

    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);

    pushup(u);
}

void modify(int u, int l, int r, int pos, char ch){
    if(l == r){
        ll cur_mn = 0;
        ll cur_sum = 0;
        if(ch == 'A'){
            cur_mn = 1;
            cur_sum = 1;
        }else{
            cur_mn = -1;
            cur_sum = -1;
        }

        tr[u] = {cur_mn,cur_sum};
        return;
    }

    int mid = (l+r)>>1;
    if(pos <= mid) modify(u<<1,l,mid,pos,ch);
    else modify(u<<1|1,mid+1,r,pos,ch);

    pushup(u);
}

Node query(int u, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return tr[u];
    }

    Node res = {0,0};
    int mid = (l+r)>>1;

    if(mid >= ql)
        res = merge(query(u<<1,l,mid,ql,qr),res);
    if(mid < qr)
        res = merge(res,query(u<<1|1,mid+1,r,ql,qr));

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>s>>q;
    s = " " + s;

    build(1,1,n);

    for(int i=0; i<q; i++){
        int op; cin>>op;
        if(op == 1){
            int pos; cin>>pos;
            char ch; cin>>ch;
            modify(1,1,n,pos,ch);
        }else{
            int l,r; cin>>l>>r;
            bool ok = query(1,1,n,l,r).mn >= 0;
            if(ok) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    
    return 0;
}