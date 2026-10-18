#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 3005;
char a[N][N];
char ans[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
            int d = min({x,y,n+1-x,n+1-y});
            int k = d%4;

            int nx,ny;

            if(k == 0){
                nx = x;
                ny = y;
            }else if(k == 1){
                nx = y;
                ny = n+1-x;
            }else if(k == 2){
                nx = n+1-x;
                ny = n+1-y;
            }else if(k == 3){
                nx = n+1-y;
                ny = x;
            }

            ans[nx][ny] = a[x][y];
        }
    }

    for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
            cout<<ans[x][y];
        }
        cout<<'\n';
    }
    
}