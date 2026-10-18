// 赋值加法线段树
// 区间赋值、区间加、区间最大值；建树 O(n)，操作 O(log n)
// 1<=n<N；先下传赋值再下传加法；值域严格位于 (-INF,INF)
// 保留原 changed 标记和 change/add 两套下传函数；累积加法标记也要在 ll 内
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[N],w[4*N];
ll add_lzy[4*N];
ll change_lzy[4*N];
bool changed[4*N];
void pushup(const int u){
    w[u] = max(w[2*u],w[2*u+1]);
}
void build(const int u, int L, int R){
    add_lzy[u] = change_lzy[u] = 0; // 多测重建时清掉上一次的标记。
    changed[u] = false;
    if(L==R){
        w[u] = a[L];
        return;
    }
    int M = (L+R)/2;
    build(2*u,L,M);
    build(2*u+1,M+1,R);
    pushup(u);
}
bool InRange(int L, int R, int l, int r){
    return (l<=L) && (R<=r);
}
bool OutRange(int L, int R, int l, int r){
    return (R<l) || (L>r);
}
void add_maketag(int u, int len, ll x){
    add_lzy[u] += x;
    w[u] += x;
}
void change_maketag(int u, int len, ll x){
    add_lzy[u] = 0;
    change_lzy[u] = x;
    changed[u] = true;
    w[u] = x;
}
void add_pushdown(int u, int L, int R){
    int M = (L+R)/2;
    add_maketag(2*u,M-L+1,add_lzy[u]);
    add_maketag(2*u+1,R-M,add_lzy[u]);
    add_lzy[u] = 0;
}
void change_pushdown(int u, int L, int R){
    int M = (L+R)/2;
    if(changed[u]){
        change_maketag(2*u,M-L+1,change_lzy[u]);
        change_maketag(2*u+1,R-M,change_lzy[u]);
        change_lzy[u] = 0;
        changed[u] = false;
    }
}
void add(int u, int L, int R, int l, int r, ll x){
    if(InRange(L,R,l,r)){
        add_maketag(u,R-L+1,x);
    }else if(!OutRange(L,R,l,r)){
        int M = (L+R)/2;
        change_pushdown(u,L,R);
        add_pushdown(u,L,R);
        add(2*u,L,M,l,r,x);
        add(2*u+1,M+1,R,l,r,x);
        pushup(u);
    }
}
void change(int u, int L, int R, int l, int r, ll x){
    if(InRange(L,R,l,r)){
        change_maketag(u,R-L+1,x);
    }else if(!OutRange(L,R,l,r)){
        int M = (L+R)/2;
        change_pushdown(u,L,R);
        add_pushdown(u,L,R);
        change(2*u,L,M,l,r,x);
        change(2*u+1,M+1,R,l,r,x);
        pushup(u);
    }
}
ll query(int u, int L, int R, int l, int r){
    if(InRange(L,R,l,r)){
        return w[u];
    }else if(!OutRange(L,R,l,r)){
        int M = (L+R)/2;
        change_pushdown(u,L,R);
        add_pushdown(u,L,R);
        return max(query(2*u,L,M,l,r),query(2*u+1,M+1,R,l,r));
    }else{
        return -INF;
    }
}
