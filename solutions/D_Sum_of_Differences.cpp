#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 3e5+9;
const int MOD = 998244353;
ll a[N],b[N];
ll prefix[N];

int n,m; 

int find(int x){
    int l=0, r=n+1;
    while(l+1!=r){
        int mid=(l+r)/2;
        if(a[mid]<x) l=mid;
        else r=mid;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=m ; i++) cin>>b[i];

    sort(a+1,a+1+n);

    for(int i=1 ; i<=n ; i++) prefix[i]=(prefix[i-1]+a[i])%MOD;

    ll sum=0;
    for(int i=1 ; i<=m ; i++){
        
        sum=((sum+b[i]*find(b[i]))%MOD-prefix[find(b[i])]+MOD)%MOD;
        sum=((sum+prefix[n])%MOD-prefix[find(b[i])]-(b[i]*(n-find(b[i])))%MOD+MOD)%MOD;
    }

    cout<<sum;
    
    return 0;
}