// 扩展欧几里得与逆元
// ax+by=gcd(a,b)，一般模数逆元；O(log max(a,b))
// exgcd: 0<=a,b<=1e9 且不全为0；inv: 2<=p<=1e9；无逆元返回 -1
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

// 调用示例：ll x,y; ll d=exgcd(30,18,x,y);
// 得到 30*x+18*y=d=6；解不唯一，这里返回其中一组。
// x,y 用引用传出；函数返回最大公约数，不是逆元。
ll exgcd(ll a, ll b, ll& x, ll& y){
    if(b==0){
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y,x);
    // 递归已求出 b*y+(a%b)*x=d。
    // 用 a%b=a-(a/b)*b 代入，得到当前 a,b 的系数。
    y -= (a/b)*x;
    return d;
}

// inv(3,11)=4，因为 3*4%11=1；inv(6,9)=-1，因为不互质。
// 模数不必是素数；只有 gcd(a,p)=1 才有逆元。
ll inv(ll a, ll p){
    if(p<=1) return -1;
    a %= p;
    if(a<0) a += p; // 先把负数化到 [0,p)
    ll x,y;
    if(exgcd(a,p,x,y)!=1) return -1;
    x %= p;
    if(x<0) x += p;
    return x;
}
// 普通 gcd 用 std::gcd(a,b)；本文件没有全局状态，不需要清空。
