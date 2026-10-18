#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 19930726;

ll qpow(ll base, ll n){
    ll res = 1;
    while(n){
        if(n&1) res = (res*base)%MOD;
        n/=2;
        base = (base*base)%MOD;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ll n,k; cin>>n>>k;
    string ss; cin>>ss;
    string s = "@";
    for(char c : ss){
        s += '#';
        s += c;
    }
    s += "#$";

    ll m = s.length();
    int R=0,C=0;
    vector<int> p(m);
    for(int i=1; i<m-1; i++){
        int j = 2*C-i;

        if(i<R) p[i] = min(R-i,p[j]);
        while(s[i+p[i]+1] == s[i-p[i]-1]) p[i]++;
        if(i+p[i] > R){
            R = i+p[i];
            C = i;
        }
    }

    vector<ll> cnt(n+1,0);
    for(int i=2; i<m; i+=2){
        cnt[p[i]]++;
    }

    int mx = n;
    if(n%2==0) mx--;
    for(int i=mx; i-2>=1; i-=2){
        cnt[i-2] += cnt[i];
    }

    ll ans = 1;
    ll remain = k;
    for(int i=mx; i>=1 && remain>0; i-=2){
        ll nn = min(cnt[i],remain);
        remain -= cnt[i];

        ans = (ans*qpow(i,nn))%MOD;
    }
    
    if(remain>0) cout<<-1;
    else cout<<ans;

    return 0;
}