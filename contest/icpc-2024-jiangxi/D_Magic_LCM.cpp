#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 998244353;
bool isprime[maxn];
vector<int> pr;
vector<vector<int>> p(1010);
bool cmp(int a, int b){return a > b;};
int qpow(int a, int n)
{
    int res=1;
    while(n>=1){
        if(n%2==1) res*=a;
        a*=a;
        n/=2;
    }
    return res;
}

void init(){
    int mx = 1e3;
    for(int i = 2; i <= mx; i++) isprime[i] = true;
    for(int i = 2; i <= mx; i++){
        if(isprime[i]){
            for(int j = i + i; j <= mx; j += i) isprime[j] = false;
            pr.push_back(i);
        }
    }
    return;
}
int T, n, a[maxn];
void br(int x){
    for(int i = 0; i < pr.size(); i++){
        int num = pr[i];
        if(x % num == 0){
            int cnt = 0;
            do{
                x /= num;
                cnt++;
            }while(x % num == 0);
            p[num].push_back(cnt);
        }
        if(x == 1) break;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> T; 
    while(T--){
        for(int i = 1; i <= 1e3; i++) p[i].clear();
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            br(a[i]);
        }
        for(int i = 2; i <= 1e3; i++){
            if(p[i].size() == 0) continue;
            sort(p[i].begin(), p[i].end(), cmp);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int num = 1;
            for(int j = 2; j <= 1e3; j++){
                if(p[j].size() < i) continue;
                num = (num * qpow(j, p[j][i - 1]) % mod) %mod;
            }
            ans += num;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
