#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int l=0,r=1e9+1;
    while(l+1!=r){
        int mid=(l+r)/2;
        cout<<mid<<endl;
        
        int response; cin>>response;

        if(response==0){
            return 0;
        }else if(response==-1){
            l=mid;
        }else if(response==1){
            r=mid;
        }
    } 

    return 0;
}