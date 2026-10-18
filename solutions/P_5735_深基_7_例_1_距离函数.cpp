#include<iostream>
#include<cmath>
double sq(double x);
double distance(double x1,double y1,double x2,double y2);
using namespace std;
int main(){
    double x1,y1,x2,y2,x3,y3,s1,s2,s3,ans;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    s1=distance(x1,y1,x2,y2);
    s2=distance(x1,y1,x3,y3);
    s3=distance(x2,y2,x3,y3);
    ans=s1+s2+s3;
    cout<<ans;
    return 0;
}
double sq(double x){
    return pow(x,2);
}
double distance(double x1,double y1,double x2,double y2){
    return sqrt(sq(x1-x2)+sq(y1-y2));
}