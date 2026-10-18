#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int n,l,m,ans=0,count=0;
    string num;
    cin>>n>>num;
    l=num.length();
    while(l!=0){
        int i=1;
        for(int j=1 ; j<=9 ; j++){
            if(num[l]=='j'){
                count+=pow(j,i);
                break;}
        }
        if (num[l]=='A') count+=pow(10,i);
    else if (num[l]=='B') count+=pow(11,i);
    else if (num[l]=='C') count+=pow(12,i);
    else if (num[l]=='D') count+=pow(13,i);
    else if (num[l]=='E') count+=pow(14,i);
    else if (num[l]=='F') count+=pow(15,i);
    l--;
    i++;
    }
    cin>>m;
    while(ans<count){
        
    }

}