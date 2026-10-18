#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int x,y; cin>>x>>y;
    vector<bool> p(x+1);
    for(int i=1 ; i<=x ; i++){
        if(x%i==0) p[x/i] = true;
    }

    if(y>x){
        cout<<"NO\n";
    }else if(p[y]) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}