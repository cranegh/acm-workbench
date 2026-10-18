#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<string,int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    mp["Ocelot"] = 1;
    mp["Serval"] = 2;
    mp["Lynx"] = 3;

    string x,y; cin>>x>>y;

    if(mp[x] >= mp[y]) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}