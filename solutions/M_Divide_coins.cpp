#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n,k; cin>>n>>k;
    
    for(int i=0 ; i<n-k ; i++) cout<<2;
    for(int i=0 ; i<k ; i++) cout<<3;

    return 0;
}