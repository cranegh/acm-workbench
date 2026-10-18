#include<iostream>
using namespace std;
int isprime;
void check(int k);
int main(){
    int n,a[110];
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    for (int i=0 ; i<n ; i++){
        check(a[i]);
        if(isprime==1) cout<<a[i]<<" ";
    }
    return 0;
}
void check(int k){
    isprime=1;
    if(k==1) isprime=0;
    else{
        for(int i=2 ; i<k ; i++){
            if(k%i==0){
            isprime=0;
            break;
            }
        }
    }
}    