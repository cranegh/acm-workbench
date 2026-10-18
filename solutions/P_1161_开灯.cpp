#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,t[5010],l[2000010];
    double a[5010];
    cin>>n;
    for (int i=0 ; i<n ;i++){
        cin>>a[i]>>t[i];
    }
    memset(l,-1,sizeof(l));
    for (int i=0 ; i<n ; i++){
        for (int j=1 ; j<=t[i] ; j++){
            l[int(a[i]*j)]*=-1;
        }
    }
    int i=1;
    while(1){
        if (l[i]==1){
            cout<<i<<endl;
            break;
        }
        i++;
    }
    return 0; 
}