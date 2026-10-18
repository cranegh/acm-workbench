// 单调栈
// 右侧第一个严格更大元素的位置；O(n)
// a[1..n]，n<N；不存在返回 0；大于等于时改为 >=
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3e6+9;
ll a[N],stk[N],ans[N];
void build(int n){
    int top=0;
    fill(ans,ans+n+1,0);
    for(int i=1 ; i<=n ; i++){
        while(top>0 && a[i]>a[stk[top]]){
            ans[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }
}
