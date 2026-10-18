#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stack>

using namespace std;
using ll =unsigned long long;

void solve()
{
    stack<ll> st;

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        string s; cin>>s;
        if(s=="push"){
            ll x; cin>>x;
            st.push(x);
        }else if(s=="pop"){
            if(!st.empty()) st.pop();
            else cout<<"Empty\n";
        }
        else if(s=="query"){
            if(!st.empty()) cout<<st.top()<<'\n';
            else cout<<"Anguei!\n";
        }else if(s=="size") cout<<st.size()<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}