#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 1e5+9;
bitset<N> vis;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    vector<int> a(n+1);

    for(int i=1 ; i<=n ; i++) cin>>a[i];

    ll cnt=0;
    int cur=1;
    vis[cur]=true;
    while(cur!=2)
    {
        cur=a[cur];
        if(vis[cur]){
            cout<<-1<<'\n';
            return 0;
        } 
        vis[cur]=true;
        cnt++;
    }

    cout<<cnt<<'\n';
    
    return 0;
}