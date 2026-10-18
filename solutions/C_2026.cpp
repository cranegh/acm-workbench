#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<bitset>

using namespace std;
using ll = long long;

const int N =1e7+9;
bitset<N> vis;
bitset<N> wa;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    
    int cnt=0;
    for(ll i=1 ; i*i<=n ; i++){
        for(ll j=i+1 ; i*i+j*j<=n ; j++){
            if(!vis[i*i+j*j]){
                cnt++;
                vis[i*i+j*j]=true;
            }
            else{
                if(!wa[i*i+j*j]) cnt--;
                wa[i*i+j*j]=true;
            }
        }
    }

    cout<<cnt<<'\n';
    for(int i=1 ; i<=n ; i++) if(vis[i] && !wa[i]) cout<<i<<' ';

    return 0;

}