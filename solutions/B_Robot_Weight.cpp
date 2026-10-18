#include<iostream>
using namespace std;
const int N = 1e2+9;
int a[N],in[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int x,n;
    cin>>x>>n;

    for(int i=1 ; i<=n ; i++)
    cin>>a[i];
    
    int q; cin>>q;
    while(q--){
        int p; cin>>p;
        if(in[p]==0){
            in[p]=1;
            x+=a[p];
            cout<<x<<'\n';
        }
        else if(in[p]==1){
            in[p]=0;
            x-=a[p];
            cout<<x<<'\n';
        }
    }
    return 0;
}