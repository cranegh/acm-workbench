#include<iostream>
using namespace std;
int main(){
    double s,x,l,d;
    cin>>s>>x;
    l=0,d=7;
    while(l<s-x){
        l+=d;
        d*=0.98;
    }
    double ans=l+d;
    if(ans<s+x) cout<<"y";
    else cout<<"n";
    return 0;
}