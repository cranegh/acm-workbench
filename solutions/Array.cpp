#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1 ; i<=n ; i++) cin>>v[i];

    int x; cin>>x;
    cout<<v[x];
    
    return 0;
}