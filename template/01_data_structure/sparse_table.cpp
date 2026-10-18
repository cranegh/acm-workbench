// ST 表
// 静态区间最大值；预处理 O(n log n)，查询 O(1)
// 1-index，1<=n<N；改 N 时同步改 LOG；不能套用于区间和
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 适用：数组不修改，反复询问一段区间的最大值。
// 调用例（放在 solve 中）：
// a[1]=5; a[2]=1; a[3]=7; a[4]=3; a[5]=2;
// build(5); cout << query(2,4); // 输出 7，查询含左右端点。
// 顺序：写入 a[1..n] -> build(n) 一次 -> 任意次 query(l,r)。
// 多测重新写 a 并 build 即可；修改 a 后原来的表不会自动更新。
// 要求 1<=l<=r<=n<N；LOG 层需覆盖 floor(log2(n))+1。
const int N = 200005,LOG = 18;
// f[j][i]：从 i 开始、长度为 2^j 的区间最大值。
ll a[N],f[LOG][N];
// lg[len]：不超过 len 的最大 2 的幂次，等于 floor(log2(len))。
int lg[N];
void build(int n){
    lg[1] = 0;
    for(int i=2 ; i<=n ; i++) lg[i] = lg[i/2]+1;
    for(int i=1 ; i<=n ; i++) f[0][i] = a[i];
    for(int j=1 ; j<=lg[n] ; j++){
        for(int i=1 ; i+(1<<j)-1<=n ; i++){
            // 长度 2^j 拆为前后两段，各长 2^(j-1)。
            f[j][i] = max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
        }
    }
}
ll query(int l, int r){
    int k = lg[r-l+1];
    // 左右各取长度 2^k 的段，覆盖整段；重叠不影响 max。
    // 求和不能这样做：重叠部分会被重复计算。
    return max(f[k][l],f[k][r-(1<<k)+1]);
}
