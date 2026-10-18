#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int da,int xiao);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int a[3]; cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    a[0]/=gcd(a[2],a[0]);
    a[2]/=gcd(a[2],a[0]);
    
    cout<<a[0]<<"/"<<a[2];
    return 0;
}
int gcd(int da,int xiao){
    while(xiao!=0){
        int temp=xiao;
        xiao=da%xiao;
        da=temp;
    }
    return da;
}