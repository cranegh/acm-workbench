#include<iostream>
#include<bitset>
using namespace std;
using ll = long long;
const int N = 1e3+5;
int a[N][N],d[N][N];
ll prefix[N][N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int x; cin>>x;
    cout<<bitset<16>(x)<<'\n';
    x>>=1;
    return 0;
}