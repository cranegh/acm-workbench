#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

string solve(){
    string res="";
    char s;
    while(cin>>s){
        if(s=='['){
            int k; cin>>k;
            string temp=solve();
            for(int i=1 ; i<=k ; i++) res+=temp;
        }
        else if(s==']') return res;
        else res+=s;
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cout<<solve();

    return 0;
}

