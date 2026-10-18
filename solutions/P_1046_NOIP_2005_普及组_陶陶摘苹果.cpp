#include<iostream>
using namespace std;
int main(){
    int l,cnt=0,a[10];
    for (int i=0 ; i<10 ; i++){
        cin>>a[i];
    }
    cin>>l;
    for (int i=0 ; i<10 ; i++){
        if(l+30>=a[i]) cnt++;
    }
    cout<<cnt;
    return 0;
} 