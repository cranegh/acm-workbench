#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

bool check_even(string& s){
    for(int i=1 ; 2*i-1<s.size() ; i++){
        if(s[2*i-1-1]==s[2*i-1] && s[2*i-1-1]!='?') return false;
    }
    return true;
}

bool check_odd(string& s){
    if(s[0]=='b') return false;

    for(int i=1 ; 2*i+1-1<s.size() ; i++){
        if(s[2*i-1]==s[2*i+1-1] && s[2*i-1]!='?') return false;
    }

    return true;
}

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    if(n!=s.size()){
        cout<<"NO\n";
        return;
    }

    if(n%2==0){
        if(check_even(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }else if(n%2==1){
        if(check_odd(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}