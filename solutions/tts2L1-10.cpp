#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<vector>
#include<map>
#include<set>

using namespace std;
using ll = long long;

map< string , set<string> > mp;

string getszm(string s){
    string res="";
    if (s.empty()) return "";
    for(int i=0 ; i<s.size() ; i++){
        if( (i==0 || s[i-1]==' ') && s[i]!=' ') res+=s[i];
    }
    return res;
}

void solve()
{
    int n; cin>>n;
    string dummy; getline(cin,dummy);
    for(int i=1 ; i<=n ; i++){
        string s; getline(cin,s);
        string key=getszm(s);
        mp[key].insert(s);
    }

    int q; cin>>q;
    getline(cin,dummy);
    for(int i=1 ; i<=q ; i++){
        string s; getline(cin,s);
        string key=getszm(s);
        if (!mp.count(key)) cout<<s<<'\n';
        else{
            bool flag = false;
            for(const auto &str : mp[key]){
                if(flag) cout<<'|';
                cout<<str;
                flag=true;
            }
            cout<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}