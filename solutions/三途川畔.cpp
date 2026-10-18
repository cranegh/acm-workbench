#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

int n,m; 

void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1 ; i<=n-2 ; i++) cout<<1<<' ';
    cout<<2<<' ';
    int x=n+k;
    cout<<x<<'\n';
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();


    return 0;
}