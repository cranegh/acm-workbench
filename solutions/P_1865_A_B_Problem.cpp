#include<iostream>
#include<algorithm>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 1e6+9;
ll a[N],prefix[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,m; cin>>n>>m;

    for(int i=1 ; i<=m ; i++) a[i]=1;
    a[0]=0,a[1]=0;
    for(int i=1 ; i<=m ; i++){
        if(a[i]) for(int j=2*i ; j<=m ; j+=i) a[j]=0;
    }

    for(int i=1 ; i<=m ; i++) prefix[i]=prefix[i-1]+a[i];
    
    for(int i=1 ; i<=n ; i++){
        int l,r; cin>>l>>r;
        if(l<1 || r>m){
            cout<<"Crossing the line\n";
            continue;
        }
        cout<<prefix[r]-prefix[l-1]<<'\n';
    }
    
    return 0;
}