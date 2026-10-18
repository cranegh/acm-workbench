// Z-function
// 各后缀与全串的最长公共前缀；O(n)
// 0-index；本模板约定 z[0]=n
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// z[i]：从 s[i] 开始的后缀与整个 s 的最长公共前缀长度。
// 调用例（放在 solve 中）：
// auto z=z_function("abcab"); // 得到 {5,0,0,2,0}。
// z[3]=2，因为 s[3..4]="ab" 与 s 的前两个字符相同。
// 下标从 0 开始；本模板 z[0]=s.size()，空串返回空 vector。
// 也可做匹配：对 p+'#'+t 求 z，文本位置对应的 z>=p.size() 即匹配。
// 例如 z_function("ab#ababa") 的 3、5 位置为 2，对应文本起点 0、2。
// 用拼接法时 '#' 必须不在 p、t 中；只求 z 本身没有此限制。
// 结果直接返回；所有状态均在函数内，多测不需要额外清空。
vector<int> z_function(const string& s){
    int n = s.size(); vector<int> z(n);
    for(int i=1,L=0,R=0 ; i<n ; i++){
        // [L,R] 是已知与前缀相同且右端最远的一段（闭区间）。
        // i 在段内时先复用 z[i-L]，但最多只能保证到 R。
        if(i<=R) z[i] = min(R-i+1,z[i-L]);
        // 从已确定的长度继续匹配；只有越过旧 R 的比较才会不断增长。
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>R){ L = i; R = i+z[i]-1; }
    }
    if(n) z[0] = n;
    return z;
}
