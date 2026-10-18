# E - Quiz Competition: Qualifiers 题解

## 原题链接
https://atcoder.jp/contests/abc475/tasks/abc475_e?lang=en

## 思路

- 首先想到的肯定是模拟，但`O(qkn)`的复杂度显然过高
- 于是我们注意到，所有的undetermined都有同一个前缀
- 由处理前缀的思想，想到01字典树

---

## 复杂度

初始插入 `N` 个长度为 `K` 的字符串：

\[
O(NK)
\]

每次询问：

- 删除旧字符串：`O(K)`
- 修改一位：`O(1)`
- 插入新字符串：`O(K)`
- 查询：`O(K)`

因此总复杂度：

$$
\boxed{O((N+Q)K)}
$$

Trie 节点数最坏可以按照所有曾经插入的字符串总长度估计，即：

$$
O((N+Q)K)
$$

---

## 代码

```cpp
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,k;

const int N = 12000005;
int trie[N][2];
int cnt[N];
int tot = 0;

string s[30005];

void insert(string& s, int d){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - '0';
        if(trie[u][a] == 0)
            trie[u][a] = ++tot;
        u = trie[u][a];
        cnt[u] += d;
    }
}

void query(string& s){
    int u = 0;
    int len = s.length();
    int ans = 0;

    for(int i=0; i<len; i++){
        int a = s[i] - '0';

        if(a == 0){
            u = trie[u][0];
        }else if(a == 1){
            ans += cnt[trie[u][0]];
            u = trie[u][1];
        }
    }

    ans += cnt[u];

    if(ans > m) cout<<"No\n";
    else cout<<"Yes\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m>>k;
    string t; cin>>t;
    for(int i=1; i<=n; i++){
        cin>>s[i];
        for(int j=0; j<k; j++){
            if(s[i][j] == t[j]) s[i][j] = '0';
            else s[i][j] = '1';
        }
        insert(s[i],1);
    }

    int q; cin>>q;
    for(int i=0; i<q; i++){
        int x,y; cin>>x>>y;
        insert(s[x],-1);
        
        if(s[x][y-1] == '1') s[x][y-1] = '0';
        else if(s[x][y-1] == '0') s[x][y-1] = '1';

        insert(s[x],1);
        
        if(n == m){
            bool all_one = 1;
            for(char c : s[x]){
                if(c == '0'){
                    all_one = false;
                    break;
                }
            }
            if(all_one) cout<<"No\n";
            else cout<<"Yes\n";
        }
        else{
            query(s[x]);
        }
    }

    return 0;
}
```

