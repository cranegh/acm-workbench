#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    int n,a[1010],b[1010];
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    for (int i=0 ; i<n-1 ; i++){
        b[i]=abs(a[i+1]-a[i]);
    }
    sort(b,b+n-1);
    int joy=1;
    for (int i=0 ; i<n-1 ; i++){
        if(b[i]!=i+1) joy=0;
    }
    if (joy==1) cout<<"Jolly" ;
    if (joy==0) cout<<"Not jolly";
    return 0;
}