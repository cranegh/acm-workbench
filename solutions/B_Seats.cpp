#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int ans=0;

    if(s[n-1]=='0') s+="01"; else ans++;

    if(s[0]=='0') s="10"+s; else if(n-1!=0) ans++;

    for(int i=1,l=0 ; i<s.length()-1 ; i++){
        if(s[i]=='0'){
            if(s[i-1]=='1'){
                l=i;
            }
            if(s[i+1]=='1'){
                ans+=(i-l+1)/3;
            }
        }else ans++;
    }

    cout<<ans<<'\n';
  
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}



