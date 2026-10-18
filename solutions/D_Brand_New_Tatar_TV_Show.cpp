#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int root(int x, vector<int>& fa){
    if(fa[x]==x) return x;
    else return fa[x] = root(fa[x],fa);
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    sort(a.begin(),a.end());

    vector<int> d(n+1);
    vector<int> pre(n+1+k);
    vector<int> fa(n+1);

    for(int i=1 ; i<=n ; i++) fa[i] = i;

    for(int i=0 ; i<n-1 ; i++) if(a[i]+k>=a[i+1]) fa[a[i]] = a[i+1];
    
    for(int i=0 ; i<n ; i++) d[a[i]]++;
    for(int i=1 ; i<=n+k ; i++) pre[i] = pre[i-1]+d[i];

    bool pp = false;
    for(int i=0 ; i<n ; i++){
        int x = a[i];
        int y = root(x,fa);

        int cur1 = pre[y] - pre[x-1];
        //cout<<cur<<'\n';
        
        if(cur1%2==0){
            pp = true;
            break;
        }

        int cur2 = pre[y] - pre[x];
        
    }

    if(pp) cout<<"YES\n";
    else cout<<"NO\n";

    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}