// 子集枚举
// 遍历一个 mask 的所有子集；O(2^popcount(mask))
// 含空集；所有 mask 再枚举子集总计 O(3^n)，不要保存全部结果
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 用二进制的第 i 位表示是否选第 i 个元素，mask 表示允许选择的集合。
// 只枚举 mask 中已有元素组成的子集，包含 mask 本身和空集 0。
// 调用例（放在 solve 中）：
// vector<unsigned> a;
// submasks(0b101u,[&](unsigned s){ a.push_back(s); });
// a 依次为 {5,4,1,0}，即 {0,2}、{2}、{0}、空集。
// [&] 让括号内代码可读写外部变量；把 push_back 换成自己的计算即可。
// 函数没有返回值，每得到一个子集就调用一次 work(s)，顺序从大到小。
// mask=0 时也会调用一次 work(0)；内部无全局状态，多测直接调用。
// unsigned 通常为 32 位；用 1u<<i 表示元素 i 时要求 0<=i<32。
// 若对 n 个元素的所有 mask 再枚举子集，总量 O(3^n)，只适合小 n。
template<class F>
void submasks(unsigned mask, F work){
    // s-1 借位产生下一个候选，再 &mask 去掉不在原集合中的位。
    for(unsigned s=mask ; ; s=(s-1)&mask){
        work(s);
        // 处理 0 后立即结束；否则无符号减法绕回，重新得到 mask。
        if(s==0) break;
    }
}
// n<32 时用 1u<<n；__builtin_ctz(x) 要求 x!=0。
