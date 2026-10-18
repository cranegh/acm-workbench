#include<iostream>
#include<bitset>
using namespace std;
using ll = long long;
const int N = 2e5+5;
int a[N];
int f(int x);

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    for(int i=1 ; i<=n ; i++) cout<<f(a[i])<<' ';

    return 0;
}
int f(int x){
    int cnt=0;
    while(x>0){
        if (x&1) cnt++;
        x >>=1;
    }
    return cnt;
}