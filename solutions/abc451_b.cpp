#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;
int cnta[N];
int cntb[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    for(int i=1; i<=n; i++){
        int a,b; cin>>a>>b;
        cnta[a]++;
        cntb[b]++;
    }

    for(int i=1; i<=m; i++){
        cout<<cntb[i]-cnta[i]<<'\n';
    }

    return 0;
}