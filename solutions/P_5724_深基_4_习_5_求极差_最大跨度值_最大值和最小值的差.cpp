#include<iostream>
#include<algorithm>
using ll = long long;
using namespace std;

const int N =1e2+9;
int a[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    cout<<a[n]-a[1];

    return 0;
}
