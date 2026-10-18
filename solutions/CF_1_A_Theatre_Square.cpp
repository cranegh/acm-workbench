#include<iostream>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    int x,y;
    x= (n%a==0) ? n/a : n/a+1;
    y= (m%a==0) ? m/a : m/a+1;
    int ans=x*y;
    cout<<ans;
    return 0;
}
