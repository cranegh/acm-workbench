#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e3+9;
bool idx[8],sum[N];

string s;
vector<int> idx;

void dfs(int dep){
    if(dep==idx.size()){
        return;
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--){
        cin>>s;
        for(int i=0 ; i<8 ; i++) idx[i]=false;
        for(int i=0 ; i<8 ; i++){
            if(s[i]=='-') idx.push_back(i);
        }

        dfs(idx[0]);
    }
    return 0;

}