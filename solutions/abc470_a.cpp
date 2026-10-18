#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        if(i%3) cout<<i<<'\n';
        else cout<<"Fizz\n";
    }
    
    
    return 0;
}