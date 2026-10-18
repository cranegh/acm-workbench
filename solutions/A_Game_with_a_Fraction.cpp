#include <iostream>

using namespace std;
using ll = long long;

void solve()
{
    ll p,q; cin>>p>>q;

    if(3*p==2*q){
        cout<<"Bob\n";
        return;
    }else if(3*p>2*q && q>p){
        cout<<"Bob\n";
        return;
    }

    cout<<"Alice\n";

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}