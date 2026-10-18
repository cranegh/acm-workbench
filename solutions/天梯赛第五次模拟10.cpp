#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e4+9;
vector<int> v[N];
int in_degree[N];
int n;

vector<int> temp_path;
vector<int> best_path;

void dfs(int u){
    temp_path.push_back(u);

    if(temp_path.size()>best_path.size()) best_path=temp_path;

    for(int i=0 ; i<v[u].size() ; i++) dfs(v[u][i]);
    temp_path.pop_back();
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    for(int i=0 ; i<n ; i++){
        int k; cin>>k;
        for(int j=1 ; j<=k ; j++){
            int child; cin>>child;
            v[i].push_back(child);
            in_degree[child]++;
        }
        sort(v[i].begin(),v[i].end());
    }

    int root=0;
    for(int i=0 ; i<n ; i++){
        if(in_degree[i]==0){
            root=i;
            break;
        }
    }

    dfs(root);

    cout<<best_path.size()<<'\n';
    for(int i=0 ; i<best_path.size() ; i++) cout<<best_path[i]<<(i==best_path.size()-1 ? '\n':' ');

    return 0;
}