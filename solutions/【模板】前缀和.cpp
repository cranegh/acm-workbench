#include<iostream>
using namespace std;
using ll =long long;
const int N=1e5+9;
ll a[N],prefix[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+a[i];

        while(q--){
            int l,r;
            cin>>l>>r;
            ll ans=prefix[r]-prefix[l-1];
            cout<<ans<<'\n';
        }
    }

    return 0;
}