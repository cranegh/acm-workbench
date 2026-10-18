#include<iostream>
#include<cstring>
#include<map>

using namespace std;
using ll = long long;

string n;
int k;
map<int,int> mp;

bool vis[33];

int cnt=0;
void dfs(int dep){
    if(dep==n.size()+1){
        cnt++;
        return;
    }

    for(int i=0 ; i<n.size() ; i++){
        if(mp.count(n[i]-'0')){
            vis[i]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n>>k;
    for(int i=1 ; i<=k ; i++){
        int x,y; cin>>x>>y;
        mp[x]=y;
    }

    dfs(1);

    return 0;
}