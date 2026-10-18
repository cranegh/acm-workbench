> 这题我由于非常小的问题，在赛场上查了4个小时，写一篇题解，记录我的伤痛，引以为戒

## 1. 题目到底在干什么

给定一个数组。对于一次询问 $k$，每个元素 $a_i$ 都可以选择保持不变，或者变成 $k-a_i$。我们要在所有选择方案里，让最后数组的 MEX 尽可能大。所有询问答案最后做一次异或输出。

先把一个最直接的事实写出来：想让某个数 $x$ 出现在变换后的数组里，可以拿原来的 $x$，也可以拿原来的 $k-x$。

所以，给定 $k$ 之后，从 $0$ 开始不断检查 $x$ 和 $k-x$ 有没有剩余，就可以把这个 $k$ 对应的最大 MEX 求出来。这个单次模拟本身很简单，复杂度 O(n) 。

## 2. 我的第一版：每个询问都 O(n) 模拟

一开始我没仔细算，觉得O(n)复杂度够了，直接对 $q$ 次询问分别处理：每读入一个 $k$，就复制一份计数，然后从 $0$ 开始推进 MEX。单次 $O(n)$，总复杂度 $O(qn)$。

$$
5\times 10^3 \times 5\times 10^5 = 2.5\times 10^9
$$

差不多十亿级别，交上去当然就是 TLE。

## 3. 转折：真正有用的 k 最多只有 n 种

TLE后我注意到，q虽然很大，但n很小，换句话说，我们是不是可以先预处理好k，再对每个询问以O(1)的复杂度直接计算。

先设原数组的 MEX 为 $premex$。因为 $0,1,\ldots,premex-1$ 本来就都存在，所以无论 $k$ 是多少，答案至少都是 $premex$。

如果一次询问想让答案超过 $premex$，第一步就必须把缺失的 $premex$ 造出来。原数组里没有 $premex$，因此只能找一个元素 $a_i$，让它翻转后等于 $premex$：

$$
k-a_i=premex
$$

也就是：

$$
k=a_i+premex
$$

**只有形如 $k=a_i+premex$ 的询问，才可能改变答案。这样的 $k$ 至多只有 $n$ 个；其他所有 $k$ 的答案直接就是premex。**

这一下就可以离线了：先把所有可能有效的 $k$ 预处理出来，查询时查表。原来的 $O(qn)$ 被压成了 $O(n^2+q)$。

## 4. 先计算premex

不做k-transformation处理的情况下，mex的值直接模拟就能暴力求出
```cpp
int premex = 0;
for(int i = 0; i <= maxn; i++){
    if(mp.count(i) != 0){
        premex++;
        mp[i]--;
    }else{
        break;
    }
}
```

只需要注意此时也消耗了0-premex之间这些数还有的剩余的次数这样做之后，这之后`mp` 里剩下的全是可以拿来继续扩展 MEX 的元素。

接着枚举这些剩余元素 $a_i$，把 $k=a_i+\text{premex}$ 放进候选列表 `vk`。
```cpp
vector<int> vk;
for(int i = 1; i <= n; i++){
    if(mp[a[i]]){
        int k = a[i] + premex;
        vk.push_back(k);
    }
}
```

这里 `vk` 可能有重复的 $k$，但总共最多放进去 $n$ 个，不影响 $O(n^2)$ 的复杂度。

## 5. 对每个候选 k 模拟答案

现在只剩至多 $n$ 个候选 $k$。对每个 $k$ 复制一份剩余计数 `cur`，从 `ans = premex` 开始：

- 如果 `cur[ans]` 还有，就直接用 `ans`；
- 否则看 `cur[k-ans]`，把它翻转成 `ans`；
- 两边都没有时，当前 `ans` 就是这个 $k$ 的最大 MEX。
```cpp
cur = mp;
int ans = premex;
while(cur[ans] || cur[k - ans]){
    if(cur[ans]) cur[ans]--;
    else cur[k - ans]--;
    ans++;
}
ansk[k] = ans;
```

这里先消耗哪一边其实无所谓：`ans` 和 `k-ans` 都能通过保持不变或翻转，提供这两个值，所以它们是等价的。

只需要保证消耗的是计数大于 $0$ 的一边，用掉一个就把对应计数减一。`ans` 最多推进 $O(n)$ 次。

## 6. 最后功亏一篑在else

预处理结束后，每次查询只需要判断 $k$ 在不在 `ansk` 里：不在，答案就是 `premex`；在，答案就是预处理出的 `ansk[k]`。然后把这个答案异或进 `ANS`。

我当时写成了下面这样：
```cpp
if(ansk.count(k) == 0)
    ANS ^= premex;

ANS ^= ansk[k];   // 少了 else，这句无论如何都会执行
```

行百里者半九十，我就倒在了这最简单的汇总答案的一步
漏了个else

这就导致下次如果查一样的k，就不会进入`if(ansk.count(k) == 0)`分支

真正正确的写法是：
```cpp
if(ansk.count(k) == 0) ANS ^= premex;
else ANS ^= ansk[k];
```

就这一个 `else`。我围着整套思路和模拟查了四个小时，一直 WA，赛后才发现统计答案这里少了一个分支。一个小疏漏耗掉了大量比赛时间，痛的刻骨铭心，也才有了这篇文章`我这辈子都不会忘记26年第二场ICPC网络赛K题`。

## 7. 赛后总结

这题的核心其实不是单次怎么求 MEX，而是发现：虽然 $k$ 的范围和询问数都很大，但真正可能影响答案的 $k$ 只有至多 $n$ 个。把无限范围压成有限候选之后，离线预处理就顺理成章了。

我的路线从 $O(qn)$ 暴力，到发现候选 $k$，再到 $O(n^2+q)$，主要思路已经推出来了。最后还是功亏一篑，下次应该引以为戒。

## 最终代码
```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5005;
int T, n, a[maxn];
int q, ANS;
unordered_map<int, int> mp, cur, ansk;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--){
        ANS = 0;
        mp.clear();
        ansk.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i], mp[a[i]]++;

        int premex = 0;
        for(int i = 0; i <= maxn; i++){
            if(mp.count(i) != 0){
                premex++;
                mp[i]--;
            }else{
                break;
            }
        }

        vector<int> vk;
        for(int i = 1; i <= n; i++){
            if(mp[a[i]]){
                int k = a[i] + premex;
                vk.push_back(k);
            }
        }

        for(int k : vk){
            cur = mp;
            int ans = premex;
            while(cur[ans] || cur[k - ans]){
                if(cur[ans]) cur[ans]--;
                else cur[k - ans]--;
                ans++;
            }
            ansk[k] = ans;
        }

        cin >> q;
        while(q--){
            int k;
            cin >> k;
            if(ansk.count(k) == 0) ANS ^= premex;
            else ANS ^= ansk[k];
        }
        cout << ANS << endl;
    }
    return 0;
}
```

上面版本还存在一些常数过大的问题，把ump优化成手写hash、处理候选k的复制流程优化掉后，如下：
```cpp
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 5005;
const int MOD = 200003;

int hkey[MOD];
int hval[MOD];
bool vis[MOD];
int a[maxn];

int get_pos(int x)
{
    int p = x%MOD;
    if(p<0) p += MOD;

    while(vis[p] && hkey[p] !=x )
    {
        p++;
        if(p == MOD)
        p = 0;
    }
    return p;
}

void add(int x)
{
    int p = get_pos(x);

    if(!vis[p])
    {
        vis[p] = true;
        hkey[p] = x;
    }
    hval[p]++;
}

int get(int x)
{
    int p = get_pos(x);
    if(!vis[p]) return 0;

    return hval[p];
}

void dec(int x){
    int p = get_pos(x);

    if(vis[p]) hval[p]--;
}

map<int,int> ansk;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(hval, 0, sizeof(hval));
        ansk.clear();

        int ANS = 0;
        int n; cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n; i++) add(a[i]);

        int premex = 0;
        for(int i = 0; i <= maxn; i++){
            if(get(i)){
                premex++;
                dec(i);
            }else{
                break;
            }
        }
        
        vector<int> vk;
        for(int i = 1; i <= n; i++){
            if(get(a[i])){
                int k = a[i] + premex;
                vk.push_back(k);
            }
        }
    
        for(int k : vk){
            int ans = premex;
            vector<int> changed;

            while(get(ans) || get(k-ans)){
                if(get(ans)){
                    dec(ans);
                    changed.push_back(ans);
                }
                else{
                    dec(k-ans);
                    changed.push_back(k-ans);
                }
                ans++;
            }
            
            ansk[k] = ans;
            for(int i : changed){
                add(i);
            }
        }
    
        int q; cin>>q;
        while(q--){
            int k; cin>>k;
            if(ansk.count(k) == 0) ANS ^= premex;
            else ANS ^= ansk[k];
        }
        cout<<ANS<<'\n';
    }
    
    return 0;

}
```
