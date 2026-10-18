#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100005;

ll p[N];
int cnt[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i];
    ll sum = 0;
    for(int i=1; i<=n; i++) sum += p[i];

    ll a = 0,b = 0;
    for(ll i=0; i<=n; i++){
        if(i*(n-i)==sum){
            a = i;
            b = n-i;
            break;
        }
    }

    for(int i=1; i<=n; i++){
        cnt[p[i]]++;
    }

    ll ans = ( a==b ? 1 : 2);
    for(int i=n; i>=1; i--){
        if(a == b){
            ans = ans*2%MOD;
            a--;
            cnt[b]--;
        }else{
            if(cnt[b]>0){
                a--;
                cnt[b]--;
            }else if(cnt[b]==0){
                b--;
                cnt[a]--;
            }
        }
    }

    cout<<ans;


    return 0;
}