#include<iostream>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    set<int> s;

    while(n--){
        int x; cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<'\n';
    for (auto i=s.begin() ; i!=s.end() ; i++){
        cout<<*i<<' ';
    }
    
    return 0;
}