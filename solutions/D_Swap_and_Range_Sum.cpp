#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,q; cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1 ; i<=n ; i++) cin>>v[i];

    vector<ll> pre(n+1,0);
    for(int i=1 ; i<=n ; i++) pre[i]+=pre[i-1]+v[i];

    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x;
            pre[x]+=v[x+1]-v[x];
            int temp=v[x+1];
            v[x+1]=v[x];
            v[x]=temp;
        }else if(op==2){
            int l,r; cin>>l>>r;
            ll ans=pre[r]-pre[l-1];
            cout<<ans<<'\n';
        }
    }

    return 0;
}