#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>

using namespace std;
using ll = long long; 

void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    vector<int> idx_0;
    vector<int> idx_1;

    int cnt_0=0;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='0') cnt_0++;
    }

    for(int i=0 ; i<n ; i++){
        if(s[i]=='1' && i<cnt_0) idx_1.push_back(i+1);
        if(s[i]=='0' && i>=cnt_0) idx_0.push_back(i+1);
    }

    if(idx_1.empty()) cout<<"Bob\n";
    else{
        cout<<"Alice\n";
        cout<<2*idx_1.size()<<'\n';
        for(int i=0 ; i<idx_1.size() ; i++) cout<<idx_1[i]<<' ';
        for(int i=0 ; i<idx_1.size() ; i++) cout<<idx_0[i]<<' ';
        cout<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}