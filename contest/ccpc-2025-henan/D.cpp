#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000000;
bitset<N> vis;

void init()
{
    for(int i=1 ; i<=1000 ; i++) vis[i*i]=true;
}

void solve()
{
    int nn; cin>>nn;
    bool pp=true;

    int x=0;
    int n=nn;
    while(n>0){
        int tmp=n%10;
        n/=10;
        x+=tmp;
    }

    if(vis[nn] && vis[x]) pp=true;
    else pp=false;

    if(pp) cout<<"Yes\n";
    else cout<<"No\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();

    int _=1;
    for(int i=1 ; i<=_ ; i++){
        solve();
    }

    return 0;
}