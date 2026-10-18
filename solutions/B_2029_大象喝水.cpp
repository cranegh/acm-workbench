#include<iostream>
#include<cmath>
#define PI 3.14
using namespace std;
int main(){
    int  h,r;
    cin>>h>>r;
    double V=PI*r*r*h;
    double ans=20000.0/V;
    cout<<ceil(ans);
    return 0;
}