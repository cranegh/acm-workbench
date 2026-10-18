#include<iostream>
using namespace std;
int main(){
    int n,k,xin;
    cin>>n>>k;
    int save=n;
    int num=n;
    while (save>=k){
        xin=save/k;
        save%=k;
        save+=xin;
        num+=xin;
    }
    cout<<num;
    return 0;
}