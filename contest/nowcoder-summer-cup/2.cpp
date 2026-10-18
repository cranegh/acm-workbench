#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    bool p1 = s.find("luotianyi")!=-1;
    bool p2 = s.find("miku")!=-1;
    if(p1 && !p2) cout<<"zhe shi luotianyi";
    else if(!p1 && p2) cout<<"zhe shi chuyinweilai";
    else cout<<"ca liang ni de yan jing";
    
    return 0;
}