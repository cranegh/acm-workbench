#include<iostream>
using namespace std;
int main(){
    int a[12];
    for(int i=0 ; i<12 ;i++){
        cin>>a[i];
    }
    int s=0,c=0;
    for(int i=0 ; i<12 ;i++){
        s+=300-a[i];
        if (s<0) {
            cout<<-(i+1);
            return 0;
        }
        int tmp=s;
        s-=s/100*100;
        c+=tmp/100*100;
    }
    int ans=c*1.2+s;
    cout<<ans;
    return 0;
}