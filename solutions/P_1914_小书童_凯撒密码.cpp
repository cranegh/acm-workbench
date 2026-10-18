#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,l;
    char s[60],ans[100];
    cin>>n;
    cin>>s;
    l=strlen(s);
    for (int i=0 ; i<l ;i++){
       ans[i]=(s[i]-'a'+n)%26+'a';
    }
    for (int i=0 ; i<l ;i++){
        cout<<ans[i];
    }
    return 0;
}