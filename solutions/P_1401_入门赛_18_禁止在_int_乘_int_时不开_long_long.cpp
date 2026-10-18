#include<iostream>
using namespace std;
int main(){
    long long x1,x2,y1,y2,a[4];
    cin>>x1>>x2>>y1>>y2;
    a[0]=x1*y1;
    a[1]=x1*y2;
    a[2]=x2*y1;
    a[3]=x2*y2;
    int book=1;
    for(int i=0 ; i<4 ; i++){
        if(a[i]<-2147483648||a[i]>2147483647){
            book=0;
            break;
        }
    }
    if(book==0) cout<<"long long int";
    if(book==1) cout<<"int";
    return 0;
}