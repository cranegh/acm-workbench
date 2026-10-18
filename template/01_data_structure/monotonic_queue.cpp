// 单调队列
// 长度 k 的滑动窗口最小值、最大值；O(n)
// a[1..n]，1<=k<=n<N；返回结果按窗口右端点 k..n 排列
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll a[N],q[N];

// 保留原两遍循环，只把 cout 的输出收集到 ans，便于其他题调用。
vector<ll> window_min(int n, int k){
    vector<ll> ans;
    int tail=0,head=1;
    for(int i=1 ; i<=n ; i++){
        while(head<=tail && i-q[head]+1>k) head++;
        while(head<=tail && a[i]<=a[q[tail]]) tail--;
        q[++tail]=i;
        if(i>=k) ans.push_back(a[q[head]]);
    }
    return ans;
}

vector<ll> window_max(int n, int k){
    vector<ll> ans;
    int head=1,tail=0;
    for(int i=1 ; i<=n ; i++){
        while(head<=tail && i-q[head]+1>k) head++;
        while(head<=tail && a[i]>=a[q[tail]]) tail--;
        q[++tail]=i;
        if(i>=k) ans.push_back(a[q[head]]);
    }
    return ans;
}
