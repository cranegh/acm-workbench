#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    char c1,c2;
    cin>>n1>>c1>>n2>>c2;

    if(n1>n2 || ((n1==n2) && c1<c2) ) cout<<"Yes";
    else cout<<"No";

    return 0;
}