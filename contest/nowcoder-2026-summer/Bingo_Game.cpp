#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;
int cntx[N];
int cnty[N];

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x,y; cin>>x>>y;
        cntx[x]++;
        cnty[y]++;
    }

    int mx = 0;
    for(int i=1 ; i<=n ; i++){
        if(cntx[i]>mx) mx = cntx[i];
        if(cnty[i]>mx) mx = cnty[i];
    }

    int ans = n - mx;
    cout<<ans;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}