// 整数二分
// 寻找最后一个不满足 check 的整数；O(log 区间长度) 次 check
// 0<=l<r，l+r 不溢出；check 先假后真，端点为假/真哨兵
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 在题目代码中定义 check；真表示答案应向左找。
bool check(ll mid);

ll binary_search(ll l, ll r){
    while(l+1!=r){
        ll mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
