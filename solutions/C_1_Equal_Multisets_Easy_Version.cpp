#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 2e5+9;

bitset<MAXN> used;

void solve()
{
    int n,k; cin>>n>>k;
    vector<ll> a(n+1);
    vector<ll> b(n+1);

    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++) cin>>b[i];

    for(int i=1 ; i<=k ; i++) used[a[i]]=true;

    int cnt=0;
    for(int i=1 ; i<=k ; i++) if(b[i]==-1) cnt++;

    int pp=true;
    for(int i=1 ; i<=k ; i++){
        if(b[i]!=-1 && !used[b[i]]){
            cout<<"NO\n";
            return;
        }
    }

    int l=1,r=k;
    while(r!=n){
        int in = ++r;
        int out = l++;

        used[a[out]]=false;
        used[a[in]]=true;
        
        if(b[in]==-1) continue;
        else if(b[in]==a[in]) continue;
        else if(used[b[in]] && cnt) continue;
        else{
            cout<<"NO\n";
            return;
        }

    }

    cout<<"YES\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}