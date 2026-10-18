#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    int len = s.length();

    ll ans = 0;

    for(int i=0 ; i<len ; i++){
        int mis = 0;
        for(int l=i,r=i ; l>=0 && r<len ; l--,r++){
            if(s[l]!=s[r]) mis++;
            if(mis>1) break;
            ans++;
        }
    }
    
    for(int i=1 ; i<len ; i++){
        int mis = 0;
        for(int l=i-1,r=i ; l>=0 && r<len ; l--,r++){
            if(s[l]!=s[r]) mis++;
            if(mis>1) break;
            ans++;
        }
    }

    cout<<ans<<'\n';
    
    return 0;
}