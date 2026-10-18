#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5+9;
int a[N];
int main(){
    int n; cin>>n;
    for (int i=1 ; i<=n ; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1 ; i<=n ; i++) cout<<a[i]<<' ';
    return 0;
}