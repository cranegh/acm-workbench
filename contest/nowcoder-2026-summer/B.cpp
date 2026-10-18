#include <bits/stdc++.h>
using namespace std;
#define int long long  
#define endl "\n"
const int INF=0x7FFFFFFF;
const int MAXN=2e5+5;
const int MOD=998244353;
const int Mod=1e9+7;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rd(l,r)uniform_int_distribution<int>(l,r)(rnd)
const int L=2e6+5;
int fac[L+1],invfac[L+1];
int binom(int n,int m){
    if(n<m||m<0)return 0;
    return fac[n]*invfac[m]%MOD*invfac[n-m]%MOD;
}
int qpow(int a,int b){
    int ans=1;
    int base=a%MOD;
    while(b){
        if(b&1)ans=ans*base%MOD;
        base=base*base%MOD;
        b>>=1;
    }
    return ans;
}
void init(){
    fac[0]=1;
    for(int i=1;i<=L;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    invfac[L]=qpow(fac[L],MOD-2);
    for(int i=L;i;i--){
        invfac[i-1]=invfac[i]*i%MOD;
    }
}


int iniv(int n){
    return qpow(n,MOD-2);
}
void solve(){
    int n,m,c,a,b;
    cin>>n>>m>>c>>a>>b;
    if(m-n<0||(m-n)%c!=0){
        cout<<0<<endl;
        return;
    }
    int k=(m-n)/c;
    int q=qpow(b,m)*m%MOD;
    q=iniv(q);
    int p=n*qpow(a,k)*qpow(b-a,m-k)%MOD;
    int d=binom(m,k);
    
    cout<<d*p*q%MOD<<endl;
}
signed main(){
    init();
    int _;
    _=1;cin>>_;
    while(_--){
        solve();
    }
    return 0;
}