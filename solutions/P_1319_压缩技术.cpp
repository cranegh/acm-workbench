#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=0,cnt=0;
    int book=1;
    while (cin>>a){
        while (a--){
            if(book==1) cout<<0;
            if(book==-1) cout<<1;
            cnt++;
            if (cnt%n==0){
                cout<<endl;
            }
        }
        book*=-1;
    }
    return 0;
}