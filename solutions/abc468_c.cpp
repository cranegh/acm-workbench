#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> p(n); for(int i=0 ; i<n ; i++) cin>>p[i];
    vector<int> q(n); for(int i=0 ; i<n ; i++) cin>>q[i];

    int ans = 0;

    if(p>=q){
        cout<<ans<<'\n';
        return 0;
    }

    while(next_permutation(p.begin(), p.end())){
        if(p == q) break;
        ans++;
    };

    cout<<ans<<'\n';


    return 0;
}