// 快速幂
// 正模数下幂取模；O(log n)
// 0<=a<p，b>=0，1<=p<=3037000500；保留 ll 乘法，结果再 %p
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll a,b,p;

ll qpow(ll a , ll n)
{
    ll res=1;
    while(n>0){
        if(n%2==1) res=(res*a)%p;
        a=(a*a)%p;
        n/=2;
    }
    return res;
}

// 先设置全局 p，调用 qpow(a,b)%p。
