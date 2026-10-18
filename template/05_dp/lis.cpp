// 最长严格上升子序列
// 长度与一个下标方案；O(n log n)
// 返回 0-index 下标；非降序列把 lower_bound 改为 upper_bound
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 求最长严格上升子序列：可以跳过元素，但不能改变原来的先后顺序。
// 调用例（放在 solve 中）：
// vector<ll> a={3,1,2,2,4}; auto ans=lis(a);
// cout << ans.size(); // 输出长度 3。
// for(int i:ans) cout << a[i] << ' '; // 输出一组方案 1 2 4。
// 返回的是原数组下标（从 0 开始），不是数值；有多解时只返回其中一组。
// 空数组返回空 vector；状态全部在函数内，多测直接调用。
// 如果允许相等，即求非降子序列，将 lower_bound 改为 upper_bound。
vector<int> lis(const vector<ll>& a){
    // d[j] 是长度 j+1 的上升子序列的最小末尾值；d 本身不一定是方案。
    vector<ll> d;
    // pos[j] 是 d[j] 在原数组的位置；pre[i] 记录方案中 i 的前驱下标。
    vector<int> pos,pre(a.size(),-1),ans;
    for(int i=0 ; i<(int)a.size() ; i++){
        // 找首个 >=a[i] 的末尾替换，使相同长度更容易在后面接新元素。
        int j = lower_bound(d.begin(),d.end(),a[i])-d.begin();
        // 接在长度 j 的方案后；必须先记前驱，再修改本层 pos。
        if(j) pre[i] = pos[j-1];
        if(j==(int)d.size()){ d.push_back(a[i]); pos.push_back(i); }
        else{ d[j] = a[i]; pos[j] = i; }
    }
    if(pos.empty()) return ans;
    // 从最长方案的末尾沿 pre 倒着追溯，最后反转恢复原下标顺序。
    for(int u=pos.back() ; u!=-1 ; u=pre[u]) ans.push_back(u);
    reverse(ans.begin(),ans.end());
    return ans;
}
