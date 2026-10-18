#include<iostream>
using namespace std;
void shemian(int n);
int n,d=1,a[1100][1100];
int main(){
    cin>>n;
    while(n--){
        d*=2;
    }
    for(int i=0 ; i<d ; i++){
        for(int j=0 ; j<d ; j++){
            a[i][j]=1;
        }
    }
}
void shemian(int a[0][0],int a[d-1][d-1]){
    for(int i=0 ; i<d/2 ; i++){
        for(int j=0 ; j<d/2 ; j++){
            a[i][j]=0;
        }
    }
    if
}