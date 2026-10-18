#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N],w[4*N];
bool lzy[4*N];

void pushup(const int u){
    w[u] = w[2*u] + w[2*u+1];
}

void build(const int u, int L, int R){
    if(L==R){
        w[u] = a[L];
        return;
    }

    int M = (L+R)/2;
    build(2*u,L,M);
    build(2*u,M+1,R);
    pushup(u);
}

bool InRange(int L, int R, int l, int r){
    return (L>=l) && (R<=r);
}

bool OutRange(int L, int R, int l, int r){
    return (R<l) || (L>r); 
}

void maketag(int u, int l, int r){
    w[u] = r-l+1-w[u];
    lzy[u] ^= 1;
}

void pushdown(int u, int L, int R){
    if(!lzy[u]) return;
    int M = (L+R)/2;
    maketag(2*u,L,M);
    maketag(2*u+1,M+1,R);
    lzy[u] = false;
}

ll query(int u, int L, int R, int l, int r){
    if(InRange(L,R,l,r)){
        return w[u];
    }else if(!OutRange(L,R,l,r)){
        int M = (L+R)/2;
        pushdown(u,L,R);
        return query(2*u,L,M,l,r) + query(2*u+1,M+1,R,l,r);
    }else return 0;
}

void update(int u, int L, int R, int l, int r){
    if(InRange(L,R,l,r)){
        maketag(u,L,R);
    }else if(!OutRange(L,R,l,r)){
        int M = (L+R)/2;
        pushdown(u,L,R); 

        update(2*u,L,M,l,r);
        update(2*u+1,M+1,R,l,r);
        pushup(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    build(1,1,n);

    for(int i=0 ; i<m ; i++){
        int op,l,r; cin>>op>>l>>r;
        if(op==0){
            update(1,1,n,l,r);
        }else if(op==1){
            cout<<query(1,1,n,l,r)<<'\n';
        }
    }

    return 0;
}
