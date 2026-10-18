#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<int> a(2*n+1);
    vector<bool> had1(n+1,false);
    vector<bool> had2(n+1,false);
    for(int i=1 ; i<=2*n ; i++) cin>>a[i];

    bool p = true;

    vector<int> ans;
    for(int i=1 ; i<=2*n ; i++){
        if(p){
            if(had1[a[i]]){
                ans.push_back(i-1);
                p = !p;
                had2[a[i]] = true;
            }else had1[a[i]] = true;
        }else if(p==false){
            if(had2[a[i]]){
                ans.push_back(i-1);
                p = !p;
                had1[a[i]] = true;
            }else had2[a[i]] = true;
        }
    }

    cout<<ans.size()<<'\n';
    for(int &x : ans) cout<<x<<" ";
    cout<<'\n';


}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}