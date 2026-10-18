#include<iostream>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<vector>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> p(n);
    vector<int> a(n);

    for(int i=0 ; i<n ; i++) cin>>p[i];
    for(int i=0 ; i<n ; i++) cin>>a[i];

    vector<int> ans;

    ans.push_back(a[0]);
    for(int i=1 ; i<n ; i++){
        if(a[i]!=a[i-1]) ans.push_back(a[i]);
    }

    int j=0;
    for(int i=0 ; i<n && j<ans.size() ; i++){
        if(ans[j]==p[i]) j++;
    }

    if(j==ans.size()) cout<<"YES\n";
    else cout<<"NO\n";

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}