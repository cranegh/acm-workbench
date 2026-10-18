#include<iostream>
#include<vector>
#include<bitset>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    string s; cin>>s;
   
    int cnt=0;
    if(s[0]=='B') cnt=1;
    int ans=cnt;

    for(int i=1 ; i<s.size() ; i++){
        ans=max(ans,cnt);
        if(s[i]=='W'){
            if(s[i-1]=='B') cnt++;
            else if(s[i-1]=='W') cnt=0;
        }else if(s[i]=='B'){
            if(s[i-1]=='W') cnt++;
            else if(s[i-1]=='B') cnt=1;
        }
    }

   ans=max(ans,cnt);

   cout<<ans;
   
    
    return 0;
}