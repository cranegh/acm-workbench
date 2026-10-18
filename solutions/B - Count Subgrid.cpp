#include<iostream>
using namespace std;
char s[12][12];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++)
    for(int j=1 ; j<=n ; j++) cin>>s[i][j];
    
    return 0; 
}