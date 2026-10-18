#include<iostream>
using namespace std;
int main(){
    int n,m,a[1010]={0};
    cin>>n>>m;
    for ( int i=1 ; i<=m ; i++){
        int tmp;
        cin>>tmp;
        a[tmp]++;
    }
    for ( int i=1 ; i<=n ; i++){
        while(a[i]--){
        cout<<i<<" ";
        }
    }
    return 0;
}    