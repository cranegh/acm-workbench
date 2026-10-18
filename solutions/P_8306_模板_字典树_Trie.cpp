#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3000005;
int trie[N][62];
int cnt[N];
int idx = 0;

void clear()
{
    for(int i=0; i<=idx; i++){
        memset(trie[i],0,sizeof(trie[i]));
        cnt[i] = 0;
    }
    idx = 0;
}

int getch(char ch)
{
    if('a' <= ch && ch <= 'z') return ch - 'a';
    if('A' <= ch && ch <= 'Z') return ch - 'A' + 26;
    return ch - '0' + 52;
}

void insert(string s){
    int p = 0;

    for(char ch : s){
        int x = getch(ch);

        if(trie[p][x] == 0){
            trie[p][x] = ++idx;
        }
        p = trie[p][x];

        cnt[p]++;
    }
}

int query(string s)
{
    int p = 0;
    for(char ch : s){
        int x = getch(ch);

        if(trie[p][x] == 0){
            return 0;
        }

        p = trie[p][x];
    }
    return cnt[p];
}

void solve()
{
    clear();

    int n,q; cin>>n>>q;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        insert(s);
    }
    for(int i=0; i<q; i++){
        string s; cin>>s;
        int res = query(s);
        cout<<res<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}