#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];

    for(int i=1; i<=n; i++){
        auto it = lower_bound(a.begin(),a.end(),i);
        int res = *it - i;

        cout<<res<<'\n';
    }

    return 0;
}