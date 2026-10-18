// 树状数组
// 保留原 lowbit / update / getsum；修改、查询 O(log n)
// 1-index，n<N；update 的 x 必须>=1；所有和与修改量不能溢出 ll
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5+9;
ll a[N],t[N];
int n,m;

int lowbit(int x){
    return x&-x;
}

// 多测时先清空树状数组，再按所需语义加入 a。
void init(int m){ n = m; fill(t,t+n+1,0); }

void update(int x, ll v){
    for(int i=x ; i<=n ; i+=lowbit(i)) t[i]+=v;
}

ll getsum(int x){
    ll res=0;
    for(int i=x ; i>0 ; i-=lowbit(i)) res+=t[i];
    return res;
}

// 原题用的是差分树状数组（区间加、单点查）：
// for(int i=1 ; i<=n ; i++) update(i,a[i]),update(i+1,-a[i]);
// 区间 [l,r] 加 v：update(l,v),update(r+1,-v)；单点 x：getsum(x)。
// 普通树状数组则只用 update(i,a[i]) 建立：单点加 update(x,v)，
// 前缀和 getsum(x)，区间和如下。普通版和差分版不能混用。
ll query(int l, int r){ return getsum(r)-getsum(l-1); }
