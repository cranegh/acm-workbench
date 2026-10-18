// 并查集
// 动态连通性；保留原来的路径压缩、直接合并写法
// init(n) 初始化 0..n-1；1-index 时自行初始化 fa[1..n]
// 不做按大小合并；单次 root 最坏 O(n)，递归长链要注意栈深
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int fa[N];
void init(int n){
    for(int i=0 ; i<n ; i++) fa[i] = i;
}
int root(int x){
    if(fa[x] == x) return x;
    return fa[x] = root(fa[x]);
}

void merge(int x, int y){
    if(root(x) != root(y)) fa[root(x)] = root(y);
}
