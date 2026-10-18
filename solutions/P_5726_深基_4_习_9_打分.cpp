#include<iostream>
#include<algorithm>
#include<iomanip>
using ll = long long;
using namespace std;
const int N =1e3+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=2 ; i<=n-1 ; i++) ans+=a[i];

    cout<<fixed<<setprecision(2)<<1.0*ans/(n-2);
    
    return 0;
}
