#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,k;
int ans = 0;

void dfs(int sum, int pos, int mn){
    if(pos==k-1 && n-sum>=mn){
        ans++;
        return;
    }

    int mx = n-sum-(k-(pos+1));
    for(int i=mn; i<=mx; i++){
        dfs(sum+i,pos+1,i);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    dfs(0,0,1);

    cout<<ans;

    return 0;
}