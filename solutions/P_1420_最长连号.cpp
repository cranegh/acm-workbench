#include<iostream>
using namespace std;
int main(){
    int n,ans=1,tmp=1,a[10010];
    cin>>n;
    for ( int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    for ( int i=0 ; i<n ; i++){
        if (a[i+1]==a[i]+1) tmp++;
        if (a[i+1]!=a[i]+1){
            if (tmp>ans) ans=tmp;
            tmp=1;
        }
    }
    cout<<ans;
    return 0;
}