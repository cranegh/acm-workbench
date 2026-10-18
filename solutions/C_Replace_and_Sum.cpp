#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 2e5+9;
int a[N],b[N],prefix[N];

void solve()
{
    int n,q; cin>>n>>q;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++) cin>>b[i];

    int cur_max=0;
    for(int i=1 ; i<=n ; i++) {
        if(b[i]>a[i]) a[i]=b[i];
    }

    for(int i=n ; i>=1 ; i--){
        if(a[i]>cur_max) cur_max=a[i];
        else a[i]=cur_max;
    }

    for(int i=1 ; i<=n ; i++) prefix[i]=prefix[i-1]+a[i];

    for(int i=1 ; i<=q; i++){
        int l,r; cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<' ';
    }
    cout<<'\n';


}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}