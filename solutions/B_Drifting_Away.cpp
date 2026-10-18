#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    string s; cin>>s;
    
    int len = s.length();
    for(int i=0 ;  i<len-1 ; i++){
        bool p1 = (s[i]=='>' && s[i+1]=='<'), p2 = (s[i]=='>' && s[i+1]=='*') ,
        p3 = (s[i]=='*' && s[i+1]=='<') , p4 = (s[i]=='*' && s[i+1]=='*');
        if(p1 || p2 || p3 || p4 ){
            cout<<-1<<'\n';
            return;
        }
    }

    int cntl=0,cntn=0,cntr=0;
    for(int i=0 ; i<len ; i++){
        if(s[i]=='<') cntl++;
        else if(s[i]=='*') cntn++;
        else if(s[i]=='>') cntr++;
    }

    int ans=max(cntl,cntr)+cntn;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}
