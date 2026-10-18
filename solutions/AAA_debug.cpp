#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+9;
ll pre[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s="01234567";

    string cur_s="";
    cur_s+=s.substr(0,1);
    cur_s+=s.substr(1+1);

    cout<<cur_s;

    return 0;
}