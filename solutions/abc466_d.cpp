#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    int ans = 0;

    vector<int> C(m+1);
    vector<int> R(m+1);

    for(int i=1 ; i<=m ; i++) cin>>R[i]>>C[i];

    vector<bool> disR(n+1,false);
    vector<bool> disC(n+1,false);

    for(int i=m ; i>=1 ; i--){
        if(!disR[R[i]] && !disC[C[i]]) ans++;

        disR[R[i]] = true;
        disC[C[i]] = true;
    }

    cout<<ans;

    return 0;
}
