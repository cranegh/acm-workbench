#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1 ; i<=n ; i++) cin>>a[i];
    
    ll best_sum=-1e18;
    int depth=1,best_depth=1;
    int i=1;

    while(i<=n){
        ll cur_sum=0;
        ll cnt = (1<<(depth-1));

        for(int j=1 ; j<=cnt ; j++){
            cur_sum+=a[i];
            i++;
        }

        if(cur_sum>best_sum){
            best_depth=depth;
            best_sum=cur_sum;
        }
        depth++;
    }

    cout<<best_depth;

    return 0;
}