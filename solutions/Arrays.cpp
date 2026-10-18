#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+5;
vector<ll> v[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        int l; cin>>l;
        for(int j=1 ; j<=l ; j++){
            ll t; cin>>t;
            v[i].push_back(t);
        }
    }

    int x,y; cin>>x>>y;
    cout<<v[x][--y];
    
    return 0;
}