#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 15;
bool vis[N][N][26];
int a[N], b[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }

    int m; cin>>m;
    vector<string> v(m);
    for(int i=0; i<m; i++) cin>>v[i];

    for(string& t : v){
        int len = t.length();
        for(int i=1; i<=len; i++){
            vis[len][i][t[i-1]-'a'] = true;
        }
    }

    for(string& t : v){
        if(t.length() != n){
            cout<<"No\n";
            continue;
        }

        bool ok = true;

        for(int i=1; i<=n; i++){
            if(!vis[a[i]][b[i]][t[i-1]-'a']){
                ok = false;
                break;
            }
        }

        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }


    return 0;
}