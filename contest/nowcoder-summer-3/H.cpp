#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;

int trie[N][52];
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
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    ll mx = 0;
    for(int i=0 ; i<n ; i++){
        string ss; cin>>ss;
        mx = max(mx,(ll)ss.length());
        insert(ss);
    }

    cout<<2*tot-mx;
}