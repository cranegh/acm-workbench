#include<iostream>
using namespace std;
int main(){
    int n,min=1000000;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a<min) min=a;
    }
    cout<<min;
    return 0;
}