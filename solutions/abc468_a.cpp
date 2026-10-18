#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> a(n); for(int i=0 ; i<n ; i++) cin>>a[i];

    int ans = 0;
    for(int i=0 ; i+2<n ; i++)
        if(a[i]<a[i+1] && a[i+1]>a[i+2]) ans++;

    cout<<ans<<'\n';

    
    return 0;
}