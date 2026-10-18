#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
const int M = 2005;
int trie[M][26];
int ed[M];
int tot = 0;

bool dp[N];

void insert(string& s){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - 'A';
        if(trie[u][a]==0)
            trie[u][a] = ++tot;
        u = trie[u][a];
    }

    ed[u]++;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s;
    while(cin>>s){
        if(s == ".") break;
        insert(s);
    }

    string t,S;
    while(cin>>t) S += t;
    int len = S.length();
    dp[0] = true;

    int ans = 0;

    for(int i=0; i<len; i++){
        if(!dp[i]) continue;

        int u = 0;
        for(int j=i; j<i+10 && j<len; j++){
            int a = S[j] - 'A';
            if(trie[u][a] == 0) break;

            u = trie[u][a];

            if(ed[u]){
                dp[j+1] = true;
                ans = max(ans,j+1);
            }
        }
    }

    cout<<ans;

    return 0;
}