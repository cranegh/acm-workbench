#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T;
    cin>>T;
    if(T==1){
        cout<<"I love Luogu!";
    } else if(T==2){
        cout<<2+4<<" "<<10-2-4;
    } else if(T==3){
        cout<<14/4<<" "<<14/4*4<<" "<<14%4;
    } else if(T==4){
        cout<<500.0/3;
    } else if(T==5){
        cout<<(260+220)/(12+20);
    } else if(T==6){
        cout<<sqrt(pow(6,2)+pow(9,2));
    } else if(T==7){
        int balance=100;
        balance+=10;
        cout<<balance<<endl;
        balance-=20;
        cout<<balance<<endl;
        balance=0;
        cout<<balance;
    } else if(T==8){
        const double PI=3.141593;
        int r=5;
        double C=2*PI*r,S=PI*r*r,V=4.0/3*PI*pow(r,3);
        cout<<C<<endl<<S<<endl<<V;
    } else if(T==9){
        int num=1;
        num=(num+1)*2;
        num=(num+1)*2;
        num=(num+1)*2;
        cout<<num;
    }else if(T==10){
        int n1=240,n2=60,t1=30,t2=6;
        double k=1.0*(n1-n2)/(t1-t2);
        double n=n2+k*(10-t2);
        cout<<n/10;
    }else if(T==11){
        cout<<100.0/(8-5);
    }else if(T==12){////
        int ans1;
        char ans2;
        ans1='M'-'A'+1;
        ans2='A'+18-1;
        cout<<ans1<<endl;
        cout<<ans2;
    }else if(T==13){
        const double PI=3.141593;
        int r1=4,r2=10;
        double V1,V2,V,l;
        V1=4.0/3*PI*r1*r1*r1,V2=4.0/3*PI*r2*r2*r2,V=V1+V2;
        l=pow(V,1.0/3);
        cout<<int(l);
    }else if(T==14){
        int a=1,b=-100,c=2400;
        double delta=pow(b,2)-4*a*c,x;
        x=1.0*(-b+sqrt(delta))/2*a;
        cout<<int(110-x+0.5);
    }
    return 0;
}   