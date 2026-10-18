#include<iostream>
using namespace std;
int main(){
    double s,step=0;
    cin>>s;
    double d=0;
    for(double v=2 ; d<s ; v=0.98*v){
        d=d+v;
        step++;
    }
    cout<<step;
    return 0;
}