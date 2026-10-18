#include<iostream>
using namespace std;
int f(int n);
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
int f(int n){
    if(n==1) return 1;
    else{
        return n*f(n-1);
    }
}
