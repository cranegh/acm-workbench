#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1000005;
int a[N];
int cnt[2005];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];

    int cur_tt = 0;
    int x = 1, y = 0;
    int mn_len = n+1;
    int ans_x = 0, ans_y = 0;

    for(x=1; x+m-1<=n; x++){
        while(cur_tt<m && y<n){
            if(y+1<=n && cnt[a[++y]]++ == 0) cur_tt++;
        }
        int len = y-x+1;
        if(len < mn_len && cur_tt == m){
            ans_x = x;
            ans_y = y;
            mn_len = len;
        }

        if(--cnt[a[x]] == 0) cur_tt--;
        
    }

    cout<<ans_x<<" "<<ans_y<<'\n';

    return 0;
}