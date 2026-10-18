#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int a[3]; for(int i=0 ; i<3 ; i++) cin>>a[i];
    sort(a,a+3);

    if(a[2]>=a[0]+a[1]) cout<<"Not triangle\n";
    else{
    if(a[2]*a[2]==a[0]*a[0]+a[1]*a[1]) cout<<"Right triangle\n";
    if(a[2]*a[2]<a[0]*a[0]+a[1]*a[1]) cout<<"Acute triangle\n";
    if(a[2]*a[2]>a[0]*a[0]+a[1]*a[1]) cout<<"Obtuse triangle\n";
    if(a[0]==a[1] || a[1]==a[2]) cout<<"Isosceles triangle\n";
    if(a[0]==a[1] && a[1]==a[2]) cout<<"Equilateral triangle\n";
    }

    return 0;
}