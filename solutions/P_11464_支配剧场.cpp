#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 35;
int a[N][N];
bitset<20> cnt;
bitset<20> had;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
            if(a[i][j] == 0) continue;
            if(!cnt[a[i][j]]) ans++;
            cnt[a[i][j]] = true;
        }
    }

    ans -= 2;

    for(int i=1; i<=m; i++) had[a[1][i]] = true;
    for(int i=1; i<=m; i++)
        if(had[a[n][i]]){
            ans++;
            break;
        }

    cout<<ans;

    return 0;
}

