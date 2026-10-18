#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    string s; cin>>s;
    int num=0;
    vector<char> a;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='0') num++;
        else a.push_back(s[i]);
    }
    sort(a.begin(),a.end());
    
    cout<<a[0];
    while(num--) cout<<0;
    for(int i=1 ; i<a.size() ; i++) cout<<a[i];
    return 0;
}