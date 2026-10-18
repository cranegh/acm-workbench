#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;
int trie[N][26],cnt[N];
int n, tot = 0;

void insert(string s){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - 'a';
        if(trie[u][a] == 0){
            trie[u][a] = ++tot;
        }
        u = trie[u][a];
        cnt[u]++;
    }
}

int query(string s){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - 'a';
        if(trie[u][a] == 0) return 0;
        u = trie[u][a];
    }
    return cnt[u];
}

void solve()
{
    string s;
    while(getline(cin,s)){
        if(s.length() == 0) break;
        insert(s);
    }
    
    while(cin>>s){
        int ans = query(s);
        cout<<ans<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}