#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5000005;
int trie[N][2], cnt[N];
int tot = 0;

void insert(int x){
    int u = 0;
    for(int i=30; i>=0; i--){
        int dig = (x>>i)&1;
        if(trie[u][dig] == 0)
            trie[u][dig] = ++tot;
        u = trie[u][dig];
        cnt[u]++;
    }
}

int query(int x){
    int u = 0;
    int ans = 0;
    
    for(int i=30; i>=0; i--){
        int r = cnt[trie[u][1]];

        if(r>=x){
            ans |= (1<<i);
            u = trie[u][1]; 
        }
        else{
            x -= r;
            u = trie[u][0];
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int m,q; cin>>m>>q;
    for(int i=0; i<m; i++){
        int x; cin>>x;
        insert(x);
    }

    for(int i=0; i<q; i++){
        int c,n; cin>>c>>n;
        if(c == 1){
            int ans = query(n);
            cout<<ans<<'\n';
        }else if(c == 2){
            insert(n);
        }
    }

    return 0;
}