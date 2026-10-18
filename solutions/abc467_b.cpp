#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        int a,b; string s;
        cin>>a>>b>>s;
        if(s=="keep") ans +=b-a;
    }

    cout<<ans<<'\n';
    
    return 0;
}