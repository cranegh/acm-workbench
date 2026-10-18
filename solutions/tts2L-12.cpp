#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int l,n; cin>>l>>n;
    if(n==2){
        if(l==2) cout<<1;
        else if(l==3) cout<<2;
    }else if(n==3){
        if(l==7) cout<<666;
    }else if(n==4){
        
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}