#include<iostream>
using namespace std;
int main(){
    int a,d=1;
    cin>>a;
    while (a>1)
    {
        a/=2,d++;
    }
    cout<<d;
    return 0;
}