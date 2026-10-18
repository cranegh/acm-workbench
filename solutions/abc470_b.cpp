#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> cnt(n+1,0);
    int mx = 0;

    for(int i=1 ; i<=n ; i++){
        int c; cin>>c;
        cnt[c]++;
        if(cnt[c] > mx) mx = cnt[c];
    }

    cout<<n-mx;
    
    return 0;
}