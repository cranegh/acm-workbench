// 双模字符串哈希
// 子串相等性快速筛选；预处理 O(n)，查询 O(1)
// 0-index 半开 [l,r)；比较时同时比较长度；仍可能碰撞，非确定性证明
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 为静态字符串预处理“指纹”，随后 O(1) 取任意子串的双模哈希。
// 调用例（放在 solve 中）：
// Hash h; h.init("ababa");
// bool same=(h.query(0,3)==h.query(2,5)); // true，两段都是 "aba"。
// query(l,r) 使用半开区间 [l,r)，包含 l、不包含 r，长度为 r-l。
// 要求先 init 且 0<=l<=r<=字符串长度；空区间返回 {0,0}。
// 比较子串时必须先保证长度相等，再比较返回的 pair<ll,ll>。
// 不同字符串可各建一个 Hash 对象；相同参数下可直接比较等长子串。
// 哈希相同仍可能碰撞；需要绝对正确时再比较原子串，会增加耗时。
// 多测再次 init 即可；修改原串后必须重新 init，不能直接沿用。
const ll MOD1 = 1000000007,MOD2 = 1000000009,B = 131;
struct Hash{
    // h1[i]/h2[i] 为前 i 个字符的哈希；p1[i]/p2[i] 为 B^i 取模。
    vector<ll> h1,h2,p1,p2;
    void init(const string& s){
        int n = s.size();
        h1.assign(n+1,0); h2.assign(n+1,0);
        p1.assign(n+1,1); p2.assign(n+1,1);
        for(int i=1 ; i<=n ; i++){
            // 按字节编码，并加 1 使字符值非零；前缀向左移一位再加字符。
            int c = (unsigned char)s[i-1]+1;
            h1[i] = (h1[i-1]*B+c)%MOD1;
            h2[i] = (h2[i-1]*B+c)%MOD2;
            p1[i] = p1[i-1]*B%MOD1; p2[i] = p2[i-1]*B%MOD2;
        }
    }
    pair<ll,ll> query(int l, int r){
        // 从前 r 位减去前 l 位的贡献；乘 B^(r-l) 对齐后半段位数。
        // 加 MOD 再取模，把减法结果调整到非负；乘积可装入 ll。
        return {(h1[r]-h1[l]*p1[r-l]%MOD1+MOD1)%MOD1,
                (h2[r]-h2[l]*p2[r-l]%MOD2+MOD2)%MOD2};
    }
};
