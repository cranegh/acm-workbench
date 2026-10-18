#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    string t; cin>>t;
    string a; cin>>a;

    bool pp = false;
    for(int i=0 ; i<n ; i++){
        if(t[i]=='o' && a[i]=='o'){
            pp = true;
            break;
        }
    }

    if(pp) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}