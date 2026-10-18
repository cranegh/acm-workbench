#include<iostream>

using namespace std;

int gcd(int x , int y){
    while(y!=0){
        int temp=x;
        x=y;
        y=temp%y;
    }
    return x;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int y1; char slash1 ; int x1; cin>>y1>>slash1>>x1;
    int y2; char slash2 ; int x2; cin>>y2>>slash2>>x2;
    int y=y1*y2; int x=x1*x2;
    int com=gcd(x,y);
    x/=com;
    y/=com;
    
    cout<<x<<' '<<y;
    return 0;
}


