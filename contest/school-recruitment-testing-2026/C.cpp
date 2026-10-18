#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;
char a[N][N];

int n; 
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int get(int x, int y){
    int res = 0;

    for(int i=0; i<8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx < 1 || ny < 1 || nx>n || ny>n){
            res++;
            continue;
        }

        if(a[nx][ny] == '*') res++;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == '*') continue;
            int cur = a[i][j] - '0';

            int num = get(i,j);
            
            int d = abs(num-cur);
            if(d != 1) ans++;
        }
    }

    cout<<ans<<endl;

}