#include<iostream>
using namespace std;
int main(){
    int n1=240,n2=60,t1=30,t2=6,n10,x;
    double k=1.0*(n1-n2)/(t1-t2);
    n10=n2+k*(10-6),x=n10/10;
    cout<<x;
    return 0;
}