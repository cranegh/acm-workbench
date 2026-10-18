#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<stack>
#include<map>
#include<set>

using namespace std;
using ll = long long;

const int N = 1e4+9;
map<string,int> mp;
set<string> st[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    cin.ignore();
    for(int i=1 ; i<=n ; i++){
        string s; getline(cin,s);
        mp[s]++;
        st[mp[s]].insert(s);
    }

    return 0;
}