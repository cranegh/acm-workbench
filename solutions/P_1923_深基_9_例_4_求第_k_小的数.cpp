#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e7+9;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,k; cin>>n>>k;
    for (int i=0 ; i<n ; i++) cin>>a[i];
    sort(a,a+n);
    cout<<a[k];
    
    return 0;
}