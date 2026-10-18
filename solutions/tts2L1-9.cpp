#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e5+9;
vector<int> a[N];

bool check(int i , int w){
    int l=0,r=a[i].size();
    while(l+1!=r){
        int mid=(l+r)/2;
        if(a[i][mid]<=w) l=mid;
        else r=mid; 
    }
    if(a[i][l]==w) return true;
    else return false;
}

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++){
        int k; cin>>k;
        for(int j=1 ; j<=k ; j++){
            int v; cin>>v;
            a[i].push_back(v);
        }
    }

    for(int i=1 ; i<=n ; i++) sort(a[i].begin(),a[i].end());

    int q; cin>>q;
    while(q--){
        int w1,w2; cin>>w1>>w2;
        int sum=0;
        for(int i=1 ; i<=n ; i++){
            if(check(i,w1) && check(i,w2)) sum++;
        }
        cout<<sum<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}