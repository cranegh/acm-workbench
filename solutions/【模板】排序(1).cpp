/*set 版
#include<iostream>
#include<set>
using namespace std;
using ll = long long;
const int N =2e5+4;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;cin>>n;
    set<int> s;
    while(n--){
        int x; cin>>x;
        s.insert(x);
    }
    for (auto i=s.begin() ; i!=s.end() ; i++){
        cout<<*i<<' ';
    }
    return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
const int N =2e5+4;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n;cin>>n;
    vector<int> s;
    while(n--){
        int x; cin>>x;
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    
    for (auto i=s.begin() ; i!=s.end() ; i++){
        cout<<*i<<' ';
    }
    return 0;
}