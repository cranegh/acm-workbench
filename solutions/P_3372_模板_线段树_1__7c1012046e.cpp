#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N],w[4*N];

void pushup(const int u){
    w[u] = w[2*u]+w[2*u+1];
}

void build(const int u, int L, int R){
    if(L==R){
        w[u] = a[L];
        return;
    }

    int M = (L+R)>>1;
    build(2*u,L,M);
    build(2*u+1,M+1,R);

    pushup(u);
}

ll query1(int u, int L, int R, int p){
    if(L==R){
        return w[u];
    }else{
        int M = (L+R)/2;
        if(M>=p) return query1(2*u,L,M,p);
        else return query1(2*u+1,M+1,R,p); 
    }
}

void update1(int u, int L, int R, int p, ll x){
    if(L==R) w[u] = x;
    else{
        int M = (L+R)/2;
        if(M>=p)
            update1(2*u,L,M,p,x);
        else
            update1(2*u+1,M+1,R,p,x);
        pushup(u);
    }
}

bool InRange(int L, int R, int l, int r){
    return (l<=L && R<=r);
}

bool Outrange(int L, int R, int l, int r){
    return (L>r || R<l);
}

ll lzy[4*N];
void maketag(int u, int len, ll x){
    lzy[u] += x;
    w[u] += len*x;
}

void pushdown(int u, int L, int R){
    int M = (L+R)/2;
    maketag(2*u,M-L+1,lzy[u]);
    maketag(2*u+1,R-M,lzy[u]);
    lzy[u] = 0;
}

ll query(int u, int L, int R, int l ,int r){
    if(InRange(L,R,l,r)) return w[u];
    else if(!Outrange(L,R,l,r)){
        pushdown(u,L,R);
        int M = (L+R)/2;
        return query(2*u,L,M,l,r)+query(2*u+1,M+1,R,l,r);
    }else return 0;
}

void update(int u, int L, int R, int l, int r, ll x){
    if(InRange(L,R,l,r)){
        maketag(u,R-L+1,x);
    }else if(!Outrange(L,R,l,r)){
        int M = (L+R)/2;
        pushdown(u,L,R);

        update(2*u,L,M,l,r,x);
        update(2*u+1,M+1,R,l,r,x);
        pushup(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    build(1,1,n);

    for(int i=0 ; i<m ; i++){
        int op; cin>>op;
        if(op==1){
            int x,y; ll k;
            cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }else if(op==2){
            int x,y; cin>>x>>y;
            cout<<query(1,1,n,x,y)<<'\n';
        }
    }

    return 0;
}
