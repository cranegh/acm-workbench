#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N = 1e4+9;

int x[N],y[N],dx[N],dy[N];


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;

    for(int i=1 ; i<=n ; i++){
        cin>>x[i]>>y[i]>>dx[i]>>dy[i];
    }

    int p,q; cin>>p>>q;
    int ans=-1;
    for(int i=1 ; i<=n ; i++){
        if(x[i]<=p && p<=x[i]+dx[i]-1 && y[i]<=q && q<=y[i]+dy[i]-1) ans=i;
    }

    cout<<ans;

    return 0;
}