// 离散化
// 值映射为有序编号；预处理 O(n log n)，查询 O(log n)
// 先 x.clear() 并加入所有值；编号从 0 开始，不保留原坐标距离
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> x;
void init(){
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
}
int getidx(ll q){
    return lower_bound(x.begin(),x.end(),q)-x.begin();
}
