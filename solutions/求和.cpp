#include<iostream>
using namespace std;
int main(){
    int n,i=1;
    double S;
    int sign=1;
    cin>>n;
    for(double factor ; i<=n ; i++){
        factor=1.0/i;
        factor*=sign;
        sign=-sign;
        S+=factor;
    }
    cout<<S<<endl;
    return 0;
}
