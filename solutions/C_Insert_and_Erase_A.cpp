#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<cmath>
#include<set>

using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    string t; cin>>t;

    string s_s="",s_t="";
    for(int i=0 ; i<s.size() ; i++) if(s[i]!='A') s_s+=s[i];
    for(int i=0 ; i<t.size() ; i++) if(t[i]!='A') s_t+=t[i];
    if(s_s!=s_t){
        cout<<-1<<'\n';
        return 0;
    }

    int cnt=0; vector<int> As;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]!='A'){
            As.push_back(cnt);
            cnt=0;
        }
        else cnt++;
    }
    As.push_back(cnt);

    cnt=0; vector<int> Ts;
    for(int i=0 ; i<t.size() ; i++){
        if(t[i]!='A'){
            Ts.push_back(cnt);
            cnt=0;
        }
        else cnt++;
    }
    Ts.push_back(cnt);

    ll ans=0;
    for(int i=0 ; i<As.size() ; i++){
        ans+=abs(As[i]-Ts[i]);
    }

    cout<<ans<<'\n';

    return 0;
}