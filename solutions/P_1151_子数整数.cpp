#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int k,check=0;
    cin>>k;
    for(int a=1 ; a<=3 ; a++)
    for(int b=0 ; b<=9 ; b++)
    for(int c=0 ; c<=9 ; c++)
    for(int d=0 ; d<=9 ; d++)
    for(int e=0 ; e<=9 ; e++){
        bool p1,p2,p3;
        p1=((100*a+10*b+c)%k==0);
        p2=((100*b+10*c+d)%k==0);
        p3=((100*c+10*d+e)%k==0);
        if (10000*a+1000*b+100*c+10*d+e<=30000){
        if (p1 && p2 && p3){
        cout<<10000*a+1000*b+100*c+10*d+e<<endl;
        check=1;
        }
    }
}
if (check==0) cout<<"No";
    return 0;
}