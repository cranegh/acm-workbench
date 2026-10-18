#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 +10;
int n, m;
int t[maxn * 4][2];
bool inrange(int L, int R, int l, int r){return L >= l && R <= r;}
bool outofrange(int L, int R, int l, int r){return L > r || R < l;}
void pushup(int u, int mod){t[u][mod] = t[u << 1][mod] + t[u << 1 | 1][mod];}
void update(int u, int L, int R, int pos, int x, int mod){
    if(L == R){
        t[u][mod] += x;
        return;
    } 
    int mid = (L + R) >> 1;
    if(mid >= pos) update(u << 1, L, mid, pos, x, mod);
    else update(u << 1 | 1, mid + 1, R, pos, x, mod);
    pushup(u, mod);
}
int query(int u, int L, int R, int l, int r, int mod){
    if(inrange(L, R, l, r)) return t[u][mod];
    else if(!outofrange(L, R, l, r)){
        int mid = (L + R) >> 1;
        return query(u << 1, L, mid, l, r, mod) + query(u << 1 | 1, mid + 1, R, l, r, mod);
    }
    else return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while(m--){
        int opt, l, r, x;
        cin >> opt;
        if(opt == 1){
            cin >> l >> r >> x;
            update(1, 1, n, l, x, 0);
            update(1, 1, n, r, x, 1);
        }
        else{
            cin >> l >> r;
            cout << query(1, 1, n, 1, r, 0) - query(1, 1, n, 1, l - 1, 1) << endl;
        }
        /*for(int i = 1; i <= 9; i++) cout << t[i] << " ";
        cout << endl;*/
    }
}