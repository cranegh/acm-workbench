#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int n,k;
vector<int> a;
vector<vector<int>> ans;

void dfs(int pos, int sum){
    if(pos == n-1){
        int res = k-sum;
        if(res%n==0){
            a[pos] = res/n;
            ans.push_back(a);
        }
        return;
    }

    int weight = pos+1;
    int mx = (k-sum)/weight;
    for(int i=0; i<=mx; i++){
        a[pos] = i;
        dfs(pos+1,sum+i*weight);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    a.assign(n,0);
    dfs(0,0);

    for(auto &x : ans){
        for(int i=0; i<n; i++){
            cout<<x[i]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}