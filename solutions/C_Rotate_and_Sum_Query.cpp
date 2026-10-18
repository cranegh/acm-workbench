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

    vector<ll> pre(2*n+1,0);
    for(int i=1 ; i<=n ; i++) pre[i]+=pre[i-1]+v[i];
    for(int i=n+1 ; i<=2*n ; i++) pre[i]+=pre[i-1]+v[i-n];

    int move=0;
    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int c; cin>>c;
            move+=c;
            move%=n;
        }else if(op==2){
            int l,r; cin>>l>>r;
            ll ans=pre[r+move]-pre[l+move-1];
            cout<<ans<<'\n';
        }
    }

    return 0;
}