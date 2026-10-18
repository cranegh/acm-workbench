#include<iostream>
using namespace std;
const int N = 1e6+9;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;

    int ans;
    for(int i=1 ; i<=n ; i++)
    cin>>a[i];
    while(m--){
        int q; cin>>q;
        int l=0,r=n;
        while(l+1!=r){
            int mid=(l+r)/2;
            if(q<=a[mid]) r=mid;
            else l=mid;
        }
        if(q==a[r]) ans=r;
        else ans=-1;
        cout<<ans<<' ';
    }
    return 0;
}