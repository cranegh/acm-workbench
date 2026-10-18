#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> p(n+1);
    for(int i=2; i<=n; i++){
        cin>>p[i];
    }

    int m; cin>>m;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];

    int mn = n+2;
    for(int i=0; i<m; i++) 
        if(a[i] < mn) mn = a[i];
    
    cout<<m-1<<" ";
    for(int x : a){
        if(x != mn)
        cout<<x<<" ";
    }
    cout<<'\n';
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}