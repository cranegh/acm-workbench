#include<iostream>
#include<cstdio>
void check(int n);
using namespace std;
int isprime = 1;
int main(){
    int num[26]={0};
    char s[110];
    cin>>s;
    for (int i=0 ; s[i]!='\0' ;i++){
        num[s[i]-'a']++;
    }
    int maxn=0,minn=100;
    for (int i=0 ; i<26 ;i++){
        if(num[i]<minn && num[i]!=0){
            minn=num[i];
        }
        if(num[i]>maxn){
            maxn=num[i];
        }
    }
    int delta=maxn-minn;
    check(delta);
    if (isprime==1){
        cout<<"Lucky Word"<<endl<<delta;        
    }
    if (isprime==0){
        cout<<"No Answer"<<endl<<0;
    }
    return 0;
}
void check(int n){
    if(n==0||n==1){
        isprime=0;
    }
    else{
        for (int i=2 ; i<n ;i++){
        if(n%i==0){
            isprime=0;
            break;
            }
        }
    }    
}
