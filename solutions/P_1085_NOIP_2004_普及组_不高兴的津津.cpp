#include<iostream>
using namespace std;
int main(){
    int x,y,max=8,maxd=0;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=1;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=2;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=3;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=4;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=5;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=6;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=7;
    cin>>x>>y;
    if(x+y>max) max=x+y,maxd=8;
    cout<<maxd;
    return 0;
}