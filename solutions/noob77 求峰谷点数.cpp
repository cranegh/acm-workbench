#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int a[10010];
    int tmp,l=0,ans=0;
    while(cin>>tmp){
        int i=0;
        a[i]=tmp;
        i++;
        l++;
    }
    for(int i=1 ; i<l-1 ; i++){
        if (a[i-1]<a[i] && a[i]>a[i+1]) ans++;
        if (a[i-1]>a[i] && a[i]<a[i+1]) ans++;
    }
    cout<<ans;
    return 0;
}