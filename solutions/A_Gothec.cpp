#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<pair<int,int>,bool> mp;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    mp[{1,7}]=true;
    mp[{3,3}]=true;
    mp[{5,5}]=true;
    mp[{7,7}]=true;
    mp[{9,9}]=true;
    
    int m,d; cin>>m>>d;

    if(mp[{m,d}]) cout<<"Yes";
    else cout<<"No";

    return 0;
}