#include<bits/stdc++.h>

using namespace std;
using ll = long long;

char l[] = {'(', '[', '<'};
char r[] = {')', ']', '>'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;
    stack<char> st;

    for(char c : s){
        for(int i=0; i<3; i++){
            if(l[i] == c) st.push(c);
            
            if(r[i] == c){
                if(!st.empty() && st.top() == l[i]){
                    st.pop();
                }else{
                    cout<<"No\n";
                    return 0;
                }
            }
        }
    }

    if(st.empty()) cout<<"Yes\n";
    else cout<<"No\n";
 
}