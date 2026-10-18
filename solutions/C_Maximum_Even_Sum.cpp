#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a,b; cin>>a>>b;
    if(b%2==1){
        if(a%2==0){
            cout<<-1<<'\n';
            return;
        }
    }

    if(b%2==0){
        if((b/2)%2==1){
            if(a%2==1){
                cout<<-1<<'\n';
                return;
            }
        }
    }

    if(b%2==1){
        a *= b;
        b = 1;
        cout<<a+b<<'\n';
    }else if(b%2==0){
        ll k = b/2;
        b /= k;
        a *= k;
        cout<<a+b<<'\n';
    }
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}