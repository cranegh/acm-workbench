#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,s; cin>>n>>s;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    ll sum = 0;
    for(int i=0 ; i<n ; i++) sum += a[i];
    
    if(sum>s){
        for(int i=0 ; i<n ; i++) cout<<a[i]<<" ";
        cout<<'\n';
        return;
    }
    
    ll cnt[3]={0,0,0};
    for(int i=0 ; i<n ; i++){
        cnt[a[i]]++;
    }

    ll d = s - sum;
    if(d!=1) cout<<-1<<'\n';
    else if(d==1){
        for(int i=0 ; i<cnt[0] ; i++) cout<<0<<" ";
        for(int i=0 ; i<cnt[2] ; i++) cout<<2<<" ";
        for(int i=0 ; i<cnt[1] ; i++) cout<<1<<" ";
        cout<<'\n';
    }
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}