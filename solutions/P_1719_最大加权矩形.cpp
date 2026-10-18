#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 125;
int a[N][N];
int pre[N][N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            pre[i][j] = pre[i-1][j]+pre[i][j-1]+a[i][j]-pre[i-1][j-1];
        }
    }

    int ans = -1e8;
    for(int lenx=1 ; lenx<=n ; lenx++){
        for(int leny=1 ; leny<=n ; leny++){
            for(int x=1 ; x+lenx-1<=n ; x++){
                for(int y=1 ; y+leny-1<=n ; y++){
                    int nx = x+lenx-1;
                    int ny = y+leny-1;
                    int cur = pre[nx][ny]-pre[nx][y-1]-pre[x-1][ny]+pre[x-1][y-1];
                    if(cur>ans) ans = cur;
                }
            }
        }
    }

    cout<<ans;

    return 0;
}