#include<iostream>
using namespace std;
int main(){
    int x,k;
    cin>>k;
    for(x=2 ; x<=k ;x++){
        int isPrime=1;
        for(int i=2 ; i<x ;i++){
           if(x%i==0){
            isPrime=0;
            break;
        }
    }
    if(isPrime==1){ 
        cout<<x<<endl;
    }
    }
    return 0;
}