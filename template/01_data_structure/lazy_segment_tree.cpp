// 懒标记线段树
// 区间加、区间和；建树 O(n)，操作 O(log n)
// a[1..n]，1<=n<N；build(1,1,n) 会重置标记；区间合法且非空
// 保留原 InRange/Outrange、maketag、pushdown、update/query；区间和需在 ll 内
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
ll a[N],w[4*N],lzy[4*N];

void pushup(const int u){
    w[u] = w[2*u]+w[2*u+1];
}

void build(const int u, int L, int R){
    lzy[u] = 0; // 多测重建时清掉上一次的标记。
    if(L==R){
        w[u] = a[L];
        return;
    }

    int M = (L+R)>>1;
    build(2*u,L,M);
    build(2*u+1,M+1,R);

    pushup(u);
}

bool InRange(int L, int R, int l, int r){
    return (l<=L && R<=r);
}

bool Outrange(int L, int R, int l, int r){
    return (L>r || R<l);
}

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
