#include<iostream>
using namespace std;
int main(){
    int k,isPrime=1;
    cin>>k;
    if (k<=1) cout<<"不是素数";
    else{
    for(int i=2 ; i<k ;i++){
        if(k%i==0){
            isPrime=0;
            break;
        }
    }
    if(isPrime==1){
        cout<<"是素数"<<endl;
    }
    else if(isPrime==0){
        cout<<"不是素数"<<endl;
    }
}
    return 0;
}