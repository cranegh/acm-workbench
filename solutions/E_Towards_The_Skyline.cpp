#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 150000+5;
int pre[N];

int root(int x){
    if(pre[x]==x) return x;
    else return pre[x] = root(pre[x]);
}

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(n); 
    
    for(int i=0 ; i<n ; i++) cin>>a[i];
    
    for(int i=0 ; i<=n ; i++) pre[i]=i;

    for(int i=0 ; i<n ; i++){
        if(a[i]==1) pre[i] = i+1;
    }

    for(int i=0 ; i<m ; i++){
        int b; cin>>b;
        b--;

        int cur = b;
        int cnt = 0;

        while(cur<n){
            if(cur >= n) break;

            int nxt = cur;
            if(a[cur]>1){
                nxt += a[cur];
                cnt++;
            }else{
                nxt = root(cur);
                cnt += nxt-cur;
            }

            if(a[cur]>1) a[cur]--;
            if(a[cur]==1) pre[cur] = cur+1;

            cur = nxt;
        }

        cout<<cnt<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();
    
    return 0;
}