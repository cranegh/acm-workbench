#include<iostream>
using namespace std;
const int N = 1e6+9;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int H,B;
    cin>>H>>B;

    if(B>=H) cout<<0;
    else cout<<H-B;

    return 0;
}