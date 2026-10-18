#include<iostream>
using namespace std;
int main(){
    int n,a[10010];
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    int ans=0;
    for (int i=0 ; i<n-1 ; i++){
        int l;
        if (a[i]>a[i+1]) l=1;
        if (a[i+1]>a[i] && l==1){
            ans++;
            l=0;
        } 
    }
    cout<<ans;
    return 0;
}