#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<pair<ll,ll> , bool> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    for(int i=0; i<q; i++){
        int op;
        ll a,b;
        cin>>op>>a>>b;

        if(op == 1){
            mp[{a,b}] = true;
        }
        else if(op == 2){
            mp[{a,b}] = false;
        }
        else if(op == 3){
            if(mp[{a,b}] && mp[{b,a}]){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }

}