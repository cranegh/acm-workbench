// 线段树
// 单点赋值、区间和；建树 O(n)，操作 O(log n)
// a[1..n]，1<=n<N；build(1,1,n)，update1/query 从根调用
#include<bits/stdc++.h>

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

// 沿用原 query 的三种区间关系；单点修改版不需要懒标记下传。
ll query(int u, int L, int R, int l ,int r){
    if(InRange(L,R,l,r)) return w[u];
    else if(!Outrange(L,R,l,r)){
        int M = (L+R)/2;
        return query(2*u,L,M,l,r)+query(2*u+1,M+1,R,l,r);
    }else return 0;
}
