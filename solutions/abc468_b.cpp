#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int m,d; string s; cin>>m>>d>>s;
    vector<bool> watched(m,false);
    for(int i=0 ; i<m ; i++){
        if(s[i]=='G'){
            for(int j=0 ; j<=d ; j++){
                int l = i-j;
                int r = i+j;
                if(l>=0) watched[l] = true;
                if(r<m) watched[r] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0 ; i<m ; i++)
        if(!watched[i]) ans++;

    cout<<ans<<'\n';
    
    return 0;
}