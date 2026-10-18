#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,m,k;

const int N = 12000005;
int tire[N][2];
int cnt[N];
int tot = 0;

string s[30005];

void insert(string& s, int d){
    int u = 0;
    int len = s.length();

    for(int i=0; i<len; i++){
        int a = s[i] - '0';
        if(tire[u][a] == 0)
            tire[u][a] = ++tot;
        u = tire[u][a];
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
            u = tire[u][0];
        }else if(a == 1){
            ans += cnt[tire[u][0]];
            u = tire[u][1];
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