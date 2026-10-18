#include<iostream>
#include<vector>

using namespace std;

const int N = 10;
int a[N];
bool vis[N];
vector<vector<int>> v;
int n;

void dfs(int dep){
    if(dep==n+1){
        vector<int> temp_row;
        for(int i=1 ; i<=n ; i++){
            temp_row.push_back(a[i]);
        }
        v.push_back(temp_row);
        return;
    }

    for(int i=1 ;  i<=n ; i++){
        if(!vis[i]){
            vis[i]=true;
            a[dep]=i;
            dfs(dep+1);
            vis[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    dfs(1);

   for(int i=0 ; i<v.size() ; i++){
    for(int j=0 ; j<v[i].size() ; j++){
        cout<<v[i][j]<<' ';
    }
    cout<<endl;
    int response; cin>>response;
    if(response==1){
        return 0;
    }
   }

    return 0;
}