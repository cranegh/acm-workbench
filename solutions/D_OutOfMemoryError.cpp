#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 2e5+9; 
ll a[N];

void solve()
{
    int n,m,h; cin>>n>>m>>h;
    vector<int> v(n); for(auto &x : v) cin>>x;
    vector<int> ori_v(v);
    vector<int> last_ele_update(n,-1);
    int last_crash=-1;

    for(int i=0 ; i<m ; i++){
        int b,c; cin>>b>>c;
        b--;

        if(last_ele_update[b]<last_crash) v[b]=ori_v[b];
        v[b]+=c;
        if(v[b]>h){
            last_crash=i;
            v[b]=ori_v[b];
        }
        last_ele_update[b]=i;
    }

    for(int i=0 ; i<n ; i++){
        if(last_ele_update[i]<last_crash) v[i]=ori_v[i];
        cout<<v[i]<<' ';
    }

    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}