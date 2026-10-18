#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    double p=1.0/2*(a+b+c),ans=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<ans;
    return 0; 
}