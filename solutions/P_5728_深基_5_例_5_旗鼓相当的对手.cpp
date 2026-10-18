#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,num=0,a[1010][4];
    cin>>n;
    for(int i=1 ; i<=n ;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    for(int i=1 ; i<=n ;i++){
        for(int j=1 ; j<i ;j++){
            if(abs(a[i][1]-a[j][1])<=5 &&
               abs(a[i][2]-a[j][2])<=5 &&
               abs(a[i][3]-a[j][3])<=5 &&
               abs(a[i][1]+a[i][2]+a[i][3]-a[j][1]-a[j][2]-a[j][3])<=10
            ){
               num++; 
             }
        }
    }
    cout<<num;
    return 0;
}