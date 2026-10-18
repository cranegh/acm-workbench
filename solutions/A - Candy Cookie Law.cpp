#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int a,b,c,d; cin>>a>>b>>c>>d;
    if (c>=a && d<b ) cout<<"Yes\n";
    else  cout<<"No\n";
    return 0; 
}