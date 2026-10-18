#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<set>
#include<vector>
#include<map>

using namespace std;
using ll = long long;

const int N = 110;
int a[N];


void solve()
{
    int n,h_,l_; cin>>n>>h_>>l_;

    vector<int> v1;
    vector<int> v2;

    int h=min(h_,l_) , l=max(h_,l_); 
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        if(a[i]<=l){
            if(a[i]<=h) v1.push_back(a[i]);
            else v2.push_back(a[i]);
        }
    }

    int ans=0;
    if(v1.size()>=v2.size())  ans=(v1.size()+v2.size())/2;
    else ans=v1.size();

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}