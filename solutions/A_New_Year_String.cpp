#include<iostream>
using namespace std;

void solve()
{
    int n; cin>>n;
    string s; cin>>s;


    if(s.find("2026")!=-1) cout<<0<<'\n';
    else{
        if(s.find("2025")==-1) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}