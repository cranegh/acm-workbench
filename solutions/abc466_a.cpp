#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    bool pp = false;
    for(int i=0 ; i<n ; i++){
        int x; cin>>x;
        if(x>=0){
            pp = true;
            break;
        }
    }

    if(!pp) cout<<"Yes";
    else cout<<"No";

    return 0;
}