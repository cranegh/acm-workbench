#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    vector<int> mx(m+1,-1);

    for(int i=0 ; i<n ; i++){
        int c,s; cin>>c>>s;
        if(s>mx[c]) mx[c] = s;
    }

    for(int i=1 ; i<=m ; i++) cout<<mx[i]<<" ";

    return 0;
}