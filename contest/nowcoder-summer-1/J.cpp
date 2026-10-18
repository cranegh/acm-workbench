#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int n, m, q;
vector<int> num[maxn], opt[maxn]; // 1或 2与 3非
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) num[i].push_back(i);
    for(int i = n + 1; i <= n + m; i++){
        int opt, x, y;
        cin >> opt;
        if(opt ==  1){
            cin >> x >> y;
            
        }
    }
}