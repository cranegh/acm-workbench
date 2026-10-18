#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

const int N = 5e6+9;
int a[N],d[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,p; cin>>n>>p;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++) d[i]=a[i]-a[i-1];

    while(p--){
        int x,y,z; cin>>x>>y>>z;
        d[x]+=z;
        d[y+1]-=z;
    }

    for(int i=1 ; i<=n ; i++) a[i]=a[i-1]+d[i];

    sort(a+1,a+1+n);
    cout<<a[1];

    return 0;
}