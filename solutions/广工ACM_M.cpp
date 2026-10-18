#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>

using namespace std;
using ll = long long;

const int N = 2e5+9;
vector<int> c[N];

void solve(){
    int n; cin>>n;

    for(int i=1; i<=n ; i++) c[i].clear();

    for(int i=1 ; i<n ; i++){
        int u,v; cin>>u>>v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    int idx=1,sum=0;

    for(int i=1 ; i<=n ; i++){
        ll cur_sum=0;
        for(int j=0 ; j<c[i].size() ; j++){
            cur_sum+=c[c[i][j]].size()-1;
        }
        if(cur_sum>sum){ sum=cur_sum ; idx=i ; }
    }
    
    cout<<idx<<' '<<sum<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}
