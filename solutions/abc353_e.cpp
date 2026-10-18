#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 300005;
ll trie[N][26], cnt[N];
ll tot = 0;
ll ans = 0;

void insert(string& s){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - 'a';
        if(trie[u][a] == 0)
            trie[u][a] = ++tot;
        
        u = trie[u][a];
        ans += cnt[u];
        cnt[u]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=0; i<n; i++){
        string t; cin>>t;
        insert(t);
    }

    cout<<ans;

    return 0;
}