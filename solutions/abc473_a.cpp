#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;

int main(){
    int n; cin>>n;

    int ans = 0;
    for(int i=1 ; i<=n ; i++){
        int a; cin>>a;
        if(i>n/2) ans += a;
    }
    cout<<ans;

    return 0;
}