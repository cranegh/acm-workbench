#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

map<string,string> mp;

string getszm(string s){
    string res="";
    res+=s[0];
    for(int i=1 ; i<s.size() ; i++){
        if(s[i-1]==' ') res+=s[i];
    }
    return res;
}

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        string s; getline(cin,s);
        string key=getszm(s);
        if( !mp[key].size()) mp[key]=s;
        else{
            mp[key]+="|";
            mp[key]+=s;
        }
    }

    int q; cin>>q;
    for(int i=1 ; i<=q ; i++){
        string s; getline(cin,s);
        string key=getszm(s);
        cout<<mp[key]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}
