#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) cin>>p[i];
    
    bool pp = true;
    int groups = n/10;
    for(int i=1; i<=groups; i++){
        int mx = i*10;
        for(int j=mx-9; j<=mx; j++){
            if(p[j] > mx){
                pp = false;
                break;
            }
        }
        if(!pp) break;
    }

    if(pp) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}