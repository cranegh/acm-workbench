#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int h,w; cin>>h>>w;
    
    for(int i=0 ; i<w ; i++) cout<<"#"; cout<<'\n';
    for(int i=0 ; i<h-2 ; i++){
        cout<<"#";
        for(int j=0 ; j<w-2 ; j++) cout<<".";
        cout<<"#\n";
    }
    for(int i=0 ; i<w ; i++) cout<<"#"; cout<<'\n';

    return 0;
}