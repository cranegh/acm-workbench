#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];
    vector<int> b(n); for(int i=0 ; i<n ; i++) cin>>b[i];

    int cnt11 = 0;
    int cnt00 = 0;
    int cnt01 = 0;
    int cnt10 = 0;

    for(int i=0 ; i<n ; i++){
        if(a[i]==1 && b[i]==0) cnt10++;
        if(a[i]==0 && b[i]==1) cnt01++;
        if(a[i]==1 && b[i]==1) cnt11++;
        if(a[i]==0 && b[i]==0) cnt00++;
    }

    if(cnt10==0 && cnt01==0) cout<<0<<'\n';
    else if(cnt10>0){
        if(cnt10%2==1) cout<<1<<'\n';
        else if(cnt10%2==0) cout<<2<<'\n';
    }else if(cnt10==0){
        if(cnt11==0) cout<<-1<<'\n';
        else if(cnt00==0) cout<<-1<<'\n';
        else cout<<2<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}