#include<iostream>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    int s=0;
    while(n--){
        if(0<x && x<=5){
            s+=250;
        }
        x++;
        x%=7;
    }
    cout<<s<<endl;
    return 0;
}