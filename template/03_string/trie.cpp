// Trie
// 大小写字母字典，统计完整单词次数；O(字符串长度)
// 只允许 A-Z/a-z；最多 N-1 个非根节点，约 212MB；空间不足时减 N
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;

int trie[N][52],cnt[N];
int n, tot = 0;

void insert(string s){
    int u = 0;
    int len = s.length();
    for(int i=0; i<len; i++){
        if('a'<=s[i] && s[i]<='z'){
            int a = s[i] - 'a';
            if(trie[u][a] == 0)
                trie[u][a] = ++tot;
            u = trie[u][a];
        }else{
            int a = s[i] - 'A' + 26;
            if(trie[u][a] == 0)
                trie[u][a] = ++tot;
            u = trie[u][a];
        }
    }
    cnt[u]++;
}

// 以下补充查询和多测清空，insert 保留原来的大小写分支。
int query(string s){
    int u = 0;
    int len = s.length();
    for(int i=0; i<len; i++){
        int a;
        if('a'<=s[i] && s[i]<='z') a = s[i]-'a';
        else a = s[i]-'A'+26;
        if(trie[u][a] == 0) return 0;
        u = trie[u][a];
    }
    return cnt[u];
}

void init(){
    for(int i=0; i<=tot; i++){
        fill(trie[i],trie[i]+52,0);
        cnt[i] = 0;
    }
    tot = 0;
}
