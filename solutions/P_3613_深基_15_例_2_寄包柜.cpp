#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>

using namespace std;
using ll =long long;
const int N = 1e5+9;
map< pair<int,int> , int > v;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,q; cin>>n>>q;
    for(int i=1 ; i<=q ; i++){
        int x; cin>>x;
        if(x==1){
            int i,j,k; cin>>i>>j>>k;
            v[{i,j}]=k;
        }else if(x==2){
            int i,j; cin>>i>>j;
            cout<<v[{i,j}]<<'\n';
        }
    }

    return 0;
}