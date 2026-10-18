#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 500005;
int trie[N][2], cnt[N], ed[N];
int n, tot = 0;

void insert(vector<int>& v){
    int u = 0;
    int len = v.size();

    for(int i=0; i<len; i++){
        int a = v[i];
        if(trie[u][a] == 0)
            trie[u][a] = ++tot;
        u = trie[u][a];
        cnt[u]++;
    }
    ed[u]++;
}

int query(vector<int>& v){
    int ans = 0;
    int u = 0;
    int len = v.size();

    for(int i=0; i<len; i++){
        int a = v[i];
        if(trie[u][a] == 0){
            return ans;
        }
        u = trie[u][a];
        ans += ed[u];
    }
    ans += cnt[u] - ed[u];
    return ans;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>m>>n;
    for(int i=0; i<m; i++){
        int k; cin>>k;
        vector<int> v(k);
        for(int j=0; j<k; j++) cin>>v[j];

        insert(v);
    }
    
    for(int i=0; i<n; i++){
        int k; cin>>k;
        vector<int> v(k);
        for(int j=0; j<k; j++) cin>>v[j];

        int ans = query(v);
        cout<<ans<<'\n';
    }


    return 0;
}