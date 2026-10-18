#include<iostream>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    int sum=0;
    for (int i=l ; i<=r ; i++){
        int num=i;
        while (num){
        int tmp=num%10;
        if (tmp==2) sum++;
        num/=10;
        }
    }
    cout<<sum;
    return 0;     
}