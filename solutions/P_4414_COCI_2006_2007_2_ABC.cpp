#include<iostream>
#include<algorithm>
using namespace std;
int a[3]; 
int f(char x);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=0 ; i<3 ; i++) cin>>a[i];
    sort(a,a+3);

    char z[3]; cin>>z;
    for(int i=0 ; i<3 ; i++) cout<<f(z[i])<<" ";
    
    return 0;
}
int f(char x){
    if(x=='A') return a[0];
    if(x=='B') return a[1];
    if(x=='C') return a[2];
}