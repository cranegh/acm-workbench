#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 5005;
const int MOD = 200003;

int hkey[MOD];
int hval[MOD];
bool vis[MOD];
int a[maxn];

int get_pos(int x)
{
    int p = x%MOD;
    if(p<0) p += MOD;

    while(vis[p] && hkey[p] !=x )
    {
        p++;
        if(p == MOD)
        p = 0;
    }
    return p;
}

void add(int x)
{
    int p = get_pos(x);

    if(!vis[p])
    {
        vis[p] = true;
        hkey[p] = x;
    }
    hval[p]++;
}

int get(int x)
{
    int p = get_pos(x);
    if(!vis[p]) return 0;

    return hval[p];
}

void dec(int x){
    int p = get_pos(x);

    if(vis[p]) hval[p]--;
}

map<int,int> ansk;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1; cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        memset(hval, 0, sizeof(hval));
        ansk.clear();

        int ANS = 0;
        int n; cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        for(int i=1; i<=n; i++) add(a[i]);

        int premex = 0;
        for(int i = 0; i <= maxn; i++){
            if(get(i)){
                premex++;
                dec(i);
            }else{
                break;
            }
        }
        
        vector<int> vk;
        for(int i = 1; i <= n; i++){
            if(get(a[i])){
                int k = a[i] + premex;
                vk.push_back(k);
            }
        }
    
        for(int k : vk){
            int ans = premex;
            vector<int> changed;

            while(get(ans) || get(k-ans)){
                if(get(ans)){
                    dec(ans);
                    changed.push_back(ans);
                }
                else{
                    dec(k-ans);
                    changed.push_back(k-ans);
                }
                ans++;
            }
            
            ansk[k] = ans;
            for(int i : changed){
                add(i);
            }
        }
    
        int q; cin>>q;
        while(q--){
            int k; cin>>k;
            if(ansk.count(k) == 0) ANS ^= premex;
            else ANS ^= ansk[k];
        }
        cout<<ANS<<'\n';
    }
    
    return 0;

}
