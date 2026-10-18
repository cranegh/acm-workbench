#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2e5+9;
int a[N];
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int len; cin>>len;
    string s; cin>>s;

    int flip=0;
    for(int i=0 ; i<len ; i++)
    {
        if (flip%2==1){
            if(s[i]=='0') s[i]='1';
            else if(s[i]=='1') s[i]='0';
        } 
        if(s[i]=='0') continue;
        if(s[i]=='1') flip++;
        }
   
    cout<<s;

    return 0;
}
