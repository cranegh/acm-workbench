#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<bool> used(5*n+1,0);
    int cur=1;
    for(int i=0 ; i<n ; i++){
        used[cur] = 1; 
        cout<<cur<<" ";
        int last=cur;
        cur++;
        while(used[cur]) cur++;
        used[last+cur] = 1;
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}