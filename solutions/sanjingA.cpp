#include<iostream>
using namespace std;
const int N = 1e9+9;
int a[N];
int f(int x);
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++)  a[i]=i;
    
    while()
    for(int k=0 ; k<=n+1/5 ; k++)
        for(int i=5*k+1 ; i<=5*k+4 ; i++)
            a[i]=0;

        
    
    cout<<f(n);
}
int f(int x){
    for(int i=1 ; i<=4 ; i++){
        a[i]=0;
    }
}