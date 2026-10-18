#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stack>

using namespace std;
using ll =long long;

stack<char> st;

void solve()
{
    bool p=true;

    int n1=0,n2=0;

    string s; cin>>s;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='(') st.push(')');
        else if(s[i]=='[') st.push(']'); 
        else{
            if(st.empty()) p=false;
            else if(st.top()==s[i]) st.pop();
            else p=false;
        }
    }

    if(!st.empty()) p=false;


    if(p) cout<<"Yes"<<'\n';
    else cout<<"No\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();
    
    return 0;
}