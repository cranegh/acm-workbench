#include<iostream>
using namespace std;
int main(){
    int k,i=1;
    cin>>k;
    double S=1;
    for( ;S<=k; ){
       i++;
       double a=1.0/i;
       S+=a;
    }
    cout<<i;
    return 0;
}