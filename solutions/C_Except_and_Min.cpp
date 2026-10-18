#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

const int N = 3e5+9;
bitset<N> vis;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,q; cin>>n>>q;
    vector< pair<int,int> > a(n);
    for(int i=0 ; i<n ; i++){
        int temp; cin>>temp;
        a[i]={temp,i};
    }

    sort(a.begin(),a.end());

    for(int i=0 ; i<q ; i++){
        int k; cin>>k;
        vector<int> b(k);
        for(int j=0 ; j<k ; j++) cin>>b[j];
        for(int j=0 ; j<k ; j++) vis[b[j]-1]=true;

        int cur=0;
        while(vis[a[cur].second]) cur++;
        cout<<a[cur].first<<'\n';
        for(int j=0 ; j<k ; j++) vis[b[j]-1]=false;
    }

    return 0;
}