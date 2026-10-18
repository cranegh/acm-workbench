#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    string s; cin>>s;

    bool in = false;
    for(int i=0; i<n; i++){
        if(s[i] == '"') in = !in;
        if(!in && s[i] == ','){
            cout<<'.';
        }else{
            cout<<s[i];
        }
    }

    return 0;
}