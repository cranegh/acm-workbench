#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<map>

using namespace std;
using ll = long long;

int n,m; 

void solve()
{
    int n; cin>>n;
    vector<ll> v(n+1);

    for(int i=1 ; i<=n ; i++) cin>>v[i];

    ll sum=0;
    ll min_sum=0;
    int k=1;

    for(int i=1 ; i<=n ; i++){
        sum+=v[i];
        if(sum<min_sum){
            min_sum=sum;
            k=i+1;
            k%=n;
            if(k==0) k=n;
        }
    }
    cout<<k<<'\n';
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int _; cin>>_;
    while(_--) solve();


    return 0;
}