#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int h,w; cin>>h>>w;

    if(w*10000 >= 25*h*h) cout<<"Yes\n";
    else cout<<"No\n";
    
    return 0;
}