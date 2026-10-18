#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1e6+9;
int a[N];
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        for(int i=1 ; i<=n ; i++) cin>>a[i];
        ll sum=0;
        for(int i=1 ; i<=n ; i++) sum+=a[i];
        if(sum%n==0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}
