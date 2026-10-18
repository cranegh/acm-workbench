#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
ll diff[N][N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,c; cin>>n>>m>>c;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin>>diff[i][j];
        }
    }


    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            diff[i][j] -= diff[i-1][j-1];
            diff[i][j] += diff[i-1][j];
            diff[i][j] += diff[i][j-1];
        }
    }

    ll mx = -32767ll*n*m;
    int ansx = 0,ansy = 0;
    for(int i=1 ; i+c-1<=n ; i++){
        for(int j=1 ; j+c-1<=m ; j++){
            ll cur = diff[i+c-1][j+c-1] - diff[i+c-1][j-1] - diff[i-1][j+c-1] + diff[i-1][j-1];
            if(cur>=mx){
                mx = cur;
                ansx = i;
                ansy = j;
            }
        }
    }

    cout<<ansx<<" "<<ansy;

    return 0;
}
