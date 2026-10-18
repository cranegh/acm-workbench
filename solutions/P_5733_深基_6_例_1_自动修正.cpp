#include<iostream>
using namespace std;
int main(){
    char a[110];
    cin>>a;
    for ( int i=0 ; a[i]!='\0' ; i++){
        if ('a' <= a[i] && a[i]<='z'){
            a[i]+='A'-'a';
        }
    }
    cout<<a;
    return 0;
}    