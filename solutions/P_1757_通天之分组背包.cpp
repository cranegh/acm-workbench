#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e3+9;
struct w{
    int a,b;
};

ll dp[N];
vector<w> wp[105]; 

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int z_max=0;
    int m,n; cin>>m>>n;
    for(int i=1 ; i<=n ; i++){
        int x,y,z; cin>>x>>y>>z;
        z_max=max(z_max,z);
        wp[z].push_back({x,y});
    }
    
    for(int i=1 ; i<=z_max ; i++){
        for(int j=m ; j>=0 ; j--){
            for(auto &c : wp[i]){
                if(j>=c.a){
                    dp[j]=max(dp[j],dp[j-c.a]+c.b);
                }
            }
        }
    }

    cout<<dp[m]<<'\n';
    
    return 0;
    
}