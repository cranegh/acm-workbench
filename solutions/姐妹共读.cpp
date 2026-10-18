#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

const int N = 5e5+9;

void solve()
{
    bitset<N> vis;
    ll n; cin>>n;
    ll cnt=0;

    for(int i=0 ; i<n ; i++){
        ll temp; cin>>temp;
        if(1<=temp && temp<=n && !vis[temp]){
            cnt++;
            vis[temp]=true;
        }
    }
    cout<<cnt<<'\n';
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();


    return 0;
}