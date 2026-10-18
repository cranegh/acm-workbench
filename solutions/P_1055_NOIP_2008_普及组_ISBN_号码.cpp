#include<iostream>
using namespace std;
int main(){
    
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    string s;
    cin>>s;
    int ans=(s[0]-'0')*1+(s[2]-'0')*2+(s[3]-'0')*3+(s[4]-'0')*4+(s[6]-'0')*5+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9;
    ans%=11;
    if(ans==10) ans='X';
    else ans+='0';
    if(ans==s[12]) cout<<"Right";
    else {
        s[12]=ans;
        cout<<s;
    }
    return 0;
}