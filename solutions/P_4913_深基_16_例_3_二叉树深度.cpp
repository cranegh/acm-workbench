#include<iostream>

using namespace std;
using ll = long long;

const int N = 1e6+9;
struct node{
    int l,r;
}t[N];

int dfs(int x){
    if(x==0) return 0;

    return max(dfs(t[x].l),dfs(t[x].r))+1;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>t[i].l>>t[i].r;

    cout<<dfs(1);


}